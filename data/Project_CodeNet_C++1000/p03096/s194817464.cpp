#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define N 200020
#define mod 1000000007
using namespace std;
int n,m;
int a[N];
long long dp[N],tot[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(i==1||a[i]!=a[i-1])a[++m]=a[i];
	dp[0]=1;
	for(int i=1;i<=m;i++)
	{
		tot[a[i]]+=dp[i-1],tot[a[i]]%=mod;
		dp[i]+=tot[a[i]],dp[i]%=mod;
	}
	printf("%lld\n",dp[m]);
}