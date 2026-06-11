#include <iostream>
using namespace std;
#define mod 998244353
long long fact[300005],inv[300005];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
long long ncr(int n,long long r)
{
	if (r>n)
	return 0;
	return (((fact[n]*inv[r])%mod)*inv[n-r])%mod;
}
int main()
{
	int n,ans=0;
	long long k,a,b;
	scanf("%d%lld%lld%lld",&n,&a,&b,&k);
	fact[0]=1;
	for (int i=1;i<=n;i++)
	fact[i]=(fact[i-1]*i)%mod;
	inv[n]=pow_log(fact[n],mod-2);
	for (int i=n-1;i>=0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	for (int i=0;i<=n;i++)
	{
		if (k>=i*a && (k-i*a)%b==0)
		ans=(ans+ncr(n,i)*ncr(n,(k-i*a)/b))%mod;
	}
	printf("%d",ans);
}