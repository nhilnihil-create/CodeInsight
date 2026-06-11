#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::min;
int n,A,B,p[5010],dp[5010][5010],ans;
signed main(){
	scanf("%lld%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(p[i]>j)dp[i][j]=min(dp[i][j],dp[i-1][j]+A),
				dp[i][p[i]]=min(dp[i][p[i]],dp[i-1][j]);
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
	for(int i=0;i<=n;i++)
		ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}