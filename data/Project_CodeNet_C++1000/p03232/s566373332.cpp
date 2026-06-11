#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
int n;
long long a[100010],ni[100010],s[100010],ans,jie[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%lld",&a[i]);
	ni[1]=1;
	for(int i=2;i<=n;++i)
	ni[i]=(mod-mod/i)*ni[mod%i]%mod;
	for(int i=1;i<=n;++i)
	s[i]=(s[i-1]+ni[i])%mod;
	for(int i=1;i<=n;++i)
	ans=(ans+s[n-i+1]*a[i]%mod+(s[i]-1)*a[i]%mod)%mod;
	jie[0]=1;
	for(int i=1;i<=n;++i)
	jie[i]=jie[i-1]*i%mod;
	ans=(ans*jie[n])%mod;
	printf("%lld\n",ans);
	return 0;
}