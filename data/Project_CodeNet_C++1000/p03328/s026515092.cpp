#include<stdio.h>
int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  int ans=(b-a)*(b-a+1)/2-b;
  printf("%d\n",ans);
  return 0;
}