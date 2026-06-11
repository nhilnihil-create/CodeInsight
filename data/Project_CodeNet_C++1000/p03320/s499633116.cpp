#include <bits/stdc++.h>
using namespace std;
#define ll long long
double S(ll n){
    double s=0;
    while(n){
        s+=n%10;
        n/=10;
    }
    return s;
}
ll F(ll n){
    ll f=n;
    double mn=n/S(n),s;
    for(ll d=1;d<=n;d*=10){
        ll t=n/(d*10)*(d*10)+d*10-1;
        s=t/S(t);
        if(s<mn){
            mn=s;
            f=t;
        }
    }
    return f;
}

ll k,n;
int main(){
    scanf("%lld",&k);
    for(n=1;k--;n=F(n+1))
		printf("%lld\n",n);
}