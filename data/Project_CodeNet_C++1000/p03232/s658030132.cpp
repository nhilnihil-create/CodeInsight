#include<bits/stdc++.h>
#define maxn 100005
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
ll a[maxn];
ll qpow(ll k,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=res*k%mod;
        k=k*k%mod;
        n>>=1;
    }
    return res;
}
ll inv(ll n)
{
    return qpow(n,mod-2);
}
ll sum[maxn];
int main()
{
    int n;
    ll fac=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        fac=(fac*(ll)i)%mod;
    }
    for(ll i=1;i<=n;++i)
    {
        sum[i]=(sum[i-1]+inv(i))%mod;
    }
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        ll temp=(sum[i]+(sum[n-i+1]-sum[1]))%mod;
        ans=(ans+(temp*a[i])%mod)%mod;
    }
    ans=ans*fac%mod;
    printf("%lld\n",ans);
    return 0;
}
