#include <stdio.h>
#include<stdlib.h>
#define ll long long

int main(){
  ll a,b;
  scanf("%lld %lld",&a,&b);
  if( b%a == 0 ){
    printf("%lld\n",a+b);
  }else{
    printf("%lld\n",b-a);
  }
  return 0;
}

