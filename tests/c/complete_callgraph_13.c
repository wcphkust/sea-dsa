// Similar to complete_callgraph_9.c

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

typedef int (*binfptr)(int, int);

// seadsa assumes that external calls does not return a freshly
// allocated pointer.
extern binfptr nd_binfptr();

int apply(int (*fn)(int, int), int x, int y) {
  // Possible callee for fn is only &add because above assumption
  return fn(x,y);
}
binfptr bar(int (*fn)(int, int)) {
  return fn;
}

int foo(int (*fn)(int, int), int x, int y) {
  int (* res) (int,int)  = bar(fn);
  return apply(res, x,y);
}

int main(){
  int x = foo(&add, 2, 5); 
  //int y = foo(&sub, 5, 7);
  int y = foo(nd_binfptr(), 5, 7);
  return x+y;
} 
