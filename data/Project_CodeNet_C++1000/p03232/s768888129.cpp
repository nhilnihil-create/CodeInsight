#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
const int maxn=1e5+10;
const ll mod=1e9+7;
ll fac[maxn],inv[maxn],a[maxn];
ll pow_mod(ll d,ll k){
    ll f=1;
    while(k){
        if(k&1) f=f*d%mod;
        d=d*d%mod;
        k>>=1;
    }
    return f;
}
void kb(){
    fac[0]=1;
    for(ll i=1;i<=1e5+2;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=pow_mod(i,mod-2);
        inv[i]=(inv[i]+inv[i-1])%mod;
    }
}
int main(){
    ll n;
    cin>>n;
    kb();
    for(ll i=1;i<=n;i++)cin>>a[i];
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum=(sum+a[i]*(inv[i]+inv[n-i+1]-1)%mod)%mod;
    }
    cout<<sum*fac[n]%mod<<endl;
}
