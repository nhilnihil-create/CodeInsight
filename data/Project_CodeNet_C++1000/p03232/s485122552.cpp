#include<cstdio>
#define mod 1000000007
#define N 100020
int fac[N],a[N],inv[N],ivs[N];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	fac[0]=1;for (int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[1]=1;for (int i=2;i<=n;++i) inv[i]=(1ll*mod-mod/i)*inv[mod%i]%mod;
	for (int i=1;i<=n;++i) ivs[i]=(ivs[i-1]+inv[i])%mod;
	for (int i=1;i<=n;++i) ans=(ans+(1ll*ivs[i]+ivs[n-i+1]-1)*a[i]%mod*fac[n]%mod)%mod;
	printf("%d",ans);
	return 0;
}