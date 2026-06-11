#include<cstdio>
#define mod 998244353
typedef long long ll;
ll inv[300005],c[300005];
int main()
{
	ll n,a,b,k,ans=0;scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	inv[1]=1;for(ll i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	c[0]=1;for(ll i=1;i<=n;i++) c[i]=c[i-1]*(n-i+1)%mod*inv[i]%mod;
	for(ll i=0,j;i<=n;i++)
	{
		if(a*i>k) break;
		if((k-a*i)%b==0) j=(k-a*i)/b; else continue;
		if(j>n) continue;
		ans+=c[i]*c[j]%mod,ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}