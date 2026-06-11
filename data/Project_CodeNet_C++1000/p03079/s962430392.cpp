#include <cstdio>
int main(){
  int a, b, c;
  scanf("%s %s %s", &a, &b, &c)+1;
  if (a == b && b == c) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}