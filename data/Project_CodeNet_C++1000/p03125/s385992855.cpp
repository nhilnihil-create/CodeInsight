#include <stdio.h>
using namespace std;

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  if ( b%a ) printf("%d\n", b-a);
  else printf("%d\n", b+a);
  return 0;
}