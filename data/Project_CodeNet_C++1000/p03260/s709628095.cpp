#include <stdio.h>
int main(){
  int a, b, mult1, mult2;
  scanf("%d %d", &a, &b);

  mult1=a*b*a;
  mult2=a*b*b;

  if( (mult1%2)!=0 || (mult2%2)!=0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;

}
