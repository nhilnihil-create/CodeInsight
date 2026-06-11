#include<stdio.h>
int main(void){
  long long int a,b,c,x;
  scanf("%d %d %d %d",&a,&b,&c,&x);
  long long ans=a-b;
  if(x&1){
    ans=-1*ans;
  }
  printf("%lld\n",ans);
  return 0;
}