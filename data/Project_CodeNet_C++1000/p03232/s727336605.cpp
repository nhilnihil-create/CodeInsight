#include <cstdio>
#define ll long long
const int N=1e5+10;
const ll mod=1e9+7;
int n;
ll a[N],fac=1,inv[N],ans;
ll quickpow(ll d,ll k)
{
    ll f=1;
    while(k)
    {
        if(k&1) f=f*d%mod;
        d=d*d%mod;
        k>>=1;
    }
    return f;
}
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
int main()
{
    scanf("%d",&n);
    rep(i,1,n) fac=fac*i%mod,inv[i]=quickpow(i,mod-2),scanf("%lld",a+i);
    rep(i,1,n) (inv[i]+=inv[i-1])%=mod;
    rep(i,1,n) (ans+=a[i]*(inv[i]+inv[n-i+1]-1))%=mod;
    printf("%lld\n",ans*fac%mod);
    return 0;
}