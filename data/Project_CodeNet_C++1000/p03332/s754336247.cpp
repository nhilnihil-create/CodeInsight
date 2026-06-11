#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll inv(ll b)
{
	if(b == 1)	return 1;
	return (mod-mod/b)*inv(mod%b)%mod;
}
ll fac[N];
ll C(ll n,ll m)
{
	ll t = (fac[m]*fac[n-m])%mod;
	return (fac[n]*inv(t))%mod;
}
ll ans[N][2];
int main()
{
	ll n,i,a,b,k;
	fac[0] = 1;
	fac[1] = 1;
	for(i = 2;i <= 3e5+5;i++)
	{
		fac[i] = (fac[i-1]*i)%mod;
	}
	scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
	ll cnt = 0;
	for(i = 0;i <= n;i++)
	{
		if(k-(i*a) >= 0 && (k-a*i)%b == 0 && (k-a*i)/b <= n)
		{
			ans[cnt][0] = i;
			ans[cnt][1] = (k-a*i)/b;
			++cnt;
		}
	}
	ll res=0;
	for(i = 0;i < cnt;i++)
	{
		res = (res+C(n,ans[i][0])*C(n,ans[i][1])%mod)%mod;
	}
	printf("%lld",res);
}