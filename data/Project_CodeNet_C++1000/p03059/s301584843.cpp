#include<stdio.h>
int main(void){
  int a,b,t;
  scanf("%d %d %d",&a,&b,&t);
  int gen=t/a;
  int ans=gen*b;
  printf("%d",ans);
  return 0;
}