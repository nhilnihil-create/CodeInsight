
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
 
const int mod=998244353;
const int maxn=4e5+7;
ll fac[maxn],inv[maxn];
 
ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
 
void init(){
    fac[0]=1,fac[1]=1;
    for(int i=2;i<=maxn;i++) fac[i]=fac[i-1]*1ll*i%mod;
    inv[maxn]=power(fac[maxn],mod-2)*1ll;
    for(int i=maxn-1;i>=0;i--) inv[i]=inv[i+1]*1ll*(i+1)%mod;
}
 
ll c(ll n,ll m){
    if(m==0) return 1;
    if(n<m) return 0;
    if(n==m) return 1;
    return fac[n]*1ll*inv[m]*1ll%mod*inv[n-m]%mod;
}
 
 
int main (){
    init();
    int n,a,b;
    ll k,ans=0;
    scanf("%d %d %d %lld",&n,&a,&b,&k);
    if(k==0) { puts("1"); return 0;}
    for(int  x=1;x<=n;x++){
        if((k-a*x)%b) continue;
        ll y=(k-a*x)/b;
        ans=(ans+c(n,x)*1ll%mod*c(n,y)*1ll%mod)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
