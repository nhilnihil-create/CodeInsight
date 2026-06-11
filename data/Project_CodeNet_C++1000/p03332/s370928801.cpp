#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll MOD=998244353,N=3e5+100;
ll n,k,ans,a,b;
ll f[N],inv[N];
inline ll qpow(ll a,ll p,ll m)
{
	ll ans=1,base=a;
	while (p)
	{
		if (p&1) ans=ans*base%m;
		base=base*base%m;
		p>>=1;
	}
	return ans%m;
}
inline void pre()
{
	f[0]=1;
	for (int i=1;i<=N-1;i++)
	{
		f[i]=f[i-1]*i%MOD;
		inv[i]=qpow(f[i],MOD-2,MOD);
	}
	return ;
	}
inline ll C(ll n,ll m)
{
	if ( ! m || n == m ) return 1 ;
	if ( n < m ) return 0 ;
	return f[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	if (k==0)
	{
		printf("1\n");
		return 0;
	}
	pre();
	for (int i=1;i<=n;i++)
	{
		ll x=i,y=k-i*a;
		if (y<0||y%b) continue;
		ans=(ans+C(n,x)%MOD*C(n,y/b)%MOD)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}