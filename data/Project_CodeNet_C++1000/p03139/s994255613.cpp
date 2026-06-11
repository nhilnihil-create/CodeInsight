#include<stdio.h>
#include <stdlib.h>
int main(){
  int x,y,n;
  scanf("%d %d %d",&n,&x,&y);
  int a,b;
  a=x<y?x:y;
  b=x+y-n;
  if(b<0)
    b=0;
  printf("%d %d",a,b);

  return 0;
}