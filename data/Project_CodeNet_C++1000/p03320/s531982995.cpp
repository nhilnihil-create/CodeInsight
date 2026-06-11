#include <iostream>
#include<cstdio>
typedef long long ll;
using namespace std;

double f(ll x){
  ll sum=0;
  ll cop=x;
  while(x){
    sum+=x%10;
    x/=10;
  }
  return cop*1.0/(sum*1.0);
}

int main()
{
    //printf("%.6f %.6f\n",f(20999),f(21999));
    ll k;scanf("%lld",&k);
    ll tot=0;
    ll now=0,x=1;
    while(tot<k){
        if((now/x)%10!=9){
            now+=x;
            printf("%lld\n",now);tot++;
        }
        else{
            if(f(now+x)>f(now+10*x)){
                x=10*x;
            }
            now+=x;
            printf("%lld\n",now);tot++;
        }
        //printf("tot=%lld \n",tot);
    }
    return 0;
}