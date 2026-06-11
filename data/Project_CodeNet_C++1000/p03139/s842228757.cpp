#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int n,a,b;
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  int max,min;
  if(a>b) {
    max = b;
  } else {
    max = a;
  }
  if(a+b<n) {
    min = 0;
  } else {
    min = a+b-n;
  }
  printf("%d %d\n",max,min);
  return 0;
}
