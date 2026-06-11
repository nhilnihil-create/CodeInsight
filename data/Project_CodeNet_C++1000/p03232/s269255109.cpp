#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll sum=0;
    rep(i,n){
        sum=(sum+modpow(i+1,mod-2))%mod;
    }
    ll ans=0;
    rep(i,n){
        ans=(ans+sum*a[i])%mod;
        sum=(sum+modpow(i+2,mod-2))%mod;
        sum=(sum-modpow(n-i,mod-2))%mod;
    }
    ans=(ans+mod)%mod;
    rep(i,n){
        ans=(ans*(i+1))%mod;
    }
    cout<<ans<<endl;
}
