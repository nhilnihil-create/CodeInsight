#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101000
const ll mod=1e9+7;

int n;
ll a[N],fac[N],inv[N],sum[N],ans;

ll power(ll x,ll y) {
	ll ret=1;
	for (;y;y>>=1,x=x*x%mod)
		if (y&1) ret=ret*x%mod;
	return ret;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1; for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	
	for (int i=2;i<=n;i++) sum[i]=(sum[i-1]+fac[n]*inv[i]%mod)%mod;
	for (int i=1;i<=n;i++) (ans+=a[i]*(fac[n]+sum[i]+sum[n-i+1])%mod)%=mod;
	printf("%lld\n",ans);
	return 0;
}