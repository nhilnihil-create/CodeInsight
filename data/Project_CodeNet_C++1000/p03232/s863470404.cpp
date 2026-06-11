#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
const int mod=1e9+7;
ll pow1(ll a,ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1)
			r=r*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return r;
}
ll s[maxn],a[maxn];
ll work(int n)
{
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]*s[n-i+1]%mod;
		ans%=mod;
	}
	return ans;
}
int main()
{
	int n;scanf("%d",&n);
	ll fac=1;
	for(int i=1;i<=n;i++)
	{
		fac=fac*i%mod;
		scanf("%lld",&a[i]);
		s[i]=pow1(i,mod-2);
		s[i]=(s[i-1]+s[i])%mod;
	}
	ll ans=fac*work(n)%mod;
	reverse(a+1,a+n+1);
	ans+=fac*work(n);
	ans%=mod;
	for(int i=1;i<=n;i++)
		ans=(ans-a[i]*fac%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
