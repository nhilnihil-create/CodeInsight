#include<stdio.h>
int main(void){
  int n,i;
  double x,sum=0;
  char u[4];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lf %s",&x,u);
    if(u[0]=='J'){
      sum+=x;
    }else{
      sum+=x*380000;
    }
  }
  printf("%lf",sum);
  return 0;
}