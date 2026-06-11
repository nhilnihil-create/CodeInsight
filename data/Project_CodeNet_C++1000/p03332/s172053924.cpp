#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353LL;
const int maxn = 3000010;
ll qpow(ll a,ll x){
    ll ret=1;
    while (x){
        if (x&1)
            ret = ret*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return ret;
}
ll fac[maxn],inv[maxn];
 
ll init(){
    fac[0]=1;
    for (int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=qpow(fac[maxn-1],mod-2);
    for (int i=maxn-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
    return 0;
}
 
ll c(ll n,ll m){
    if (n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    init();
    ll N,A,B,K;
    cin>>N>>A>>B>>K;
    ll ans=0;
    for(int i=0;i<=N;i++){
        if(K-A*i<0) continue;
        if((K-A*i)%B!=0) continue;
        ll y=(K-A*i)/B;
        if(y>N)continue;
        ans=(ans+c(N,i)*c(N,y)+mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}