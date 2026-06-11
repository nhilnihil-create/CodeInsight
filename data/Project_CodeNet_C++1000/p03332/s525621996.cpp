#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5,mod=998244353;
ll n,a,b;
ll k,f[N],invf[N];
ll C(int n,int m)
{
    return f[n]*invf[n-m]%mod*invf[m]%mod;
}
int main()
{
    f[0]=f[1]=invf[0]=invf[1]=1;
    for(int i=2;i<N;i++) f[i]=f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
    for(int i=2;i<N;i++) invf[i]=invf[i-1]*invf[i]%mod;
    scanf("%lld%lld%lld",&n,&a,&b);
    scanf("%lld",&k);
    ll ans=0;
    for(int i=0;i*a<=k&&i<=n;i++)
    {
        if((k-i*a)%b) continue;
        ll s=(k-i*a)/b;
        if(s>n) continue;
        ans=(ans+C(n,i)*C(n,s))%mod;
    }
    printf("%lld\n",ans);
}
