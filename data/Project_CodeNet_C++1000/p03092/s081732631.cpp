#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int N=5100;
int n,a,b,p[N],dp[N][N];
signed main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (p[i]>j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
				dp[i][p[i]]=min(dp[i][p[i]],dp[i-1][j]);
			}
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+b);
		}
	}
	int ans=inf;
	for (int i=0;i<=n;i++) ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}