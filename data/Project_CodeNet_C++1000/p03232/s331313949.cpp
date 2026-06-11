# include <cstdio>
# include <iostream>
# define R register int
# define mod 1000000007
# define ll long long

using namespace std;

const int maxn=100005;
int n;
ll t[maxn],x[maxn];
ll s=1,ans=0;

ll inv (int a,int b)
{
	ll s=1;
	while (b)
	{
		if(b&1) s=s*a%mod;
		a=1LL*a*a%mod;
		b=b>>1;
	}
	return s;
}

int main()
{
	cin>>n;
	for (R i=1;i<=n;++i) s=s*i%mod;
	for (R i=1;i<=n;++i)
		t[i]=(t[i-1]+s*inv(i,mod-2))%mod;
	for (R i=1;i<=n;++i)
	{
		scanf("%lld",&x[i]);
		ans=(ans+(t[i]+t[n-i+1]-s)%mod*x[i]%mod)%mod;
	}
	printf("%lld",((ans%mod)+mod)%mod);
	return 0;
}