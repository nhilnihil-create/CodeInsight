#include <iostream>
using namespace std;
#define mod 1000000007
long long dp[100005],fact[100005],inv[100005];
int arr[100005];
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
int f(int n,int r)
{
	return (fact[n]*inv[r])%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	fact[0]=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		fact[i]=(fact[i-1]*i)%mod;
		dp[i]=(dp[i-1]*i+fact[i-1])%mod;
	}
	inv[n]=pow_log(fact[n],mod-2);
	for (int i=n-1;i>=0;i--)
	inv[i]=(inv[i+1]*(i+1))%mod;
	long long sum=0;
	for (int i=1;i<=n;i++)
	sum=(sum+arr[i]*((f(n,i)*dp[i]+f(n,n-i+1)*dp[n-i+1]-fact[n]+mod)%mod))%mod;
	printf("%lld",sum);
}