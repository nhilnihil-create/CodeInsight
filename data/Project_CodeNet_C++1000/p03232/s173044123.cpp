#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
ll fct[N],prfx[N],a[N],n,ans;
ll power(ll n,ll p){
    ll val=1;
    while(p){
        if(p&1)val=(val*n)%mod;
        p>>=1;
        n=(n*n)%mod;
    }
    return val;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;fct[0]=1;
    for(ll i=1;i<=n;i++)cin>>a[i],prfx[i]=(prfx[i-1]+a[i])%mod,fct[i]=(fct[i-1]*i)%mod;
    for(ll x=0;x<=n-1;x++){
        ll val = fct[n]*power(x+1,mod-2);
        val%=mod;
        val*=prfx[n-x];
        val%=mod;
        ans+=val;
        ans%=mod;
    }
    reverse(a+1,a+n+1);
    for(ll i=1;i<=n;i++)prfx[i]=(prfx[i-1]+a[i])%mod;
    for(ll x=1;x<=n-1;x++){
        ll val = fct[n]*power(x+1,mod-2);
        val%=mod;
        val*=prfx[n-x];
        val%=mod;
        ans+=val;
        ans%=mod;
    }
    cout<<ans;
}