#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL fac[200010],inv[200010],f[100010],n,sum[100010],a[100010];
LL C(LL m,LL n) {return fac[m]*inv[m-n]%mod*inv[n]%mod;}
LL solve(LL m,LL n) {return C(m+n-1,n-1);}
void pre()
{
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(LL i=2;i<=200000;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(LL i=2;i<=200000;i++) fac[i]=fac[i-1]*i%mod,inv[i]=inv[i]*inv[i-1]%mod;
	for(LL i=0;i<n;i++)
	{
		f[i]=fac[i]*fac[n-i-1]%mod*solve(n-i-1,i+2)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	//for(int i=0;i<n;i++) printf("f:%lld\n",f[i]);
}
LL ans=0;
int main()
{
	scanf("%lld",&n);
	pre();
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(LL i=1;i<=n;i++)
	{
		LL t=(sum[i-1]+sum[n-i]-fac[n])%mod;
		//printf("%lld %lld\n",i,t);
		(ans+=t*a[i]%mod)%=mod;
	}
	printf("%lld",(ans+mod)%mod);
}