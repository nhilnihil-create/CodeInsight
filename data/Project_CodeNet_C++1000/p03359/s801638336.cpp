#include <stdio.h>

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  int ans=a;
  if ( b<a ) ans--;
  printf("%d\n", ans);
  return 0;
}