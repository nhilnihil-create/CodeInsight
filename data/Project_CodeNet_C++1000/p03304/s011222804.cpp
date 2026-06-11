#include<stdio.h>
int main(){
  long long int i,a,b,c;
  double ans=0,n,m,d;
  scanf("%lld %lld %lld\n",&a,&b,&c);
  n=a,m=b,d=c;
  if(d==0){
    ans=n/n/n;
  }
  else{
    ans=2*(n-d)/(n*n);
  }
  ans=ans*(m-1);
  printf("%.10lf\n",ans);
  return 0;
}