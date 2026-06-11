#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll k;
ll now=0,x=1;
double f(ll x){
    double sum=0,t=x;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return (double)t*1.0/sum*1.0;
}
int main(){
    scanf("%lld",&k);
    while(k--){
        if((now/x)%10!=9){
            now+=x;
            printf("%lld\n",now);
        }
        else{
            if(f(now+x)>f(now+10*x))
                x*=10;
            now+=x;
            printf("%lld\n",now);
        }
    }
    return 0;
}