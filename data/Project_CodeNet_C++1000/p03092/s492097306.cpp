#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a,b,p[5050],dy[5050];
long long dp[5050][5050],ans=0x3f3f3f3f3f3f3f3f;
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),dy[p[i]]=i;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		long long mi=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<=n;++j)
		{
			mi=min(mi,dp[i-1][j]);
			dp[i][j]=min(dp[i][j],mi+(j>=dy[i]?a:b));
			if(j+1==dy[i])dp[i][j+1]=min(dp[i][j+1],mi);
		}
	}
	for(int i=0;i<=n;++i)ans=min(ans,dp[n][i]);
	printf("%lld",ans);
	return 0;
}
