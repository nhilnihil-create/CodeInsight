#include<cstdio>
using namespace std;
#define N 5005
long long dp[N][N];
int n,a,b,p[N];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=1e17;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		long long mn=1e18;
		for(int j=0;j<=n;j++)
		{
			long long tp=mn;
			if(p[i]>j)tp+=a;
			if(p[i]<j)tp+=b;
			if(dp[i][j]>tp)dp[i][j]=tp;
			if(mn>dp[i-1][j])mn=dp[i-1][j];
			tp=mn;
			if(p[i]>j)tp+=a;else tp+=b;
			if(dp[i][j]>tp)dp[i][j]=tp;
		}
	}
	long long as=1e18;
	for(int i=0;i<=n;i++)if(as>dp[n][i])as=dp[n][i];
	printf("%lld\n",as);
}//