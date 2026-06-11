#include<stdio.h>
int main(void){
  int a1,a2,a3;
  int max,min;
  scanf("%d %d %d",&a1,&a2,&a3);
  if(a1>=a2){
    max=a1;
    min=a2;
  }else if(a1<=a2){
    max=a2;
    min=a1;
  }
  if(max<=a3){
    max=a3;
  }
  if(min>=a3){
    min=a3;
  }
  int ans=max-min;
  printf("%d",ans);
  return 0;
}