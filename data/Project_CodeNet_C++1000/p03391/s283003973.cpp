#include<stdio.h>
int main(){
long long n,a,b,i,ans=0,min=100000000000;
scanf("%lld",&n);
for(i=0;i<n;i++){
scanf("%lld%lld",&a,&b);
if(a>b&&b<min)
min=b;
  ans+=a;
}
  if(min>=10000000000)
    printf("0\n");
  else
printf("%lld\n",ans-min);
return 0;
}
