#include <bits/stdc++.h>
using namespace std;
const int N=310;
int n,m,dp[N][N][N];
char s[N];
int main()
{
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) dp[i][i][0]=1;
	for (int len=2;len<=n;len++)
	{
		for (int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			for (int k=0;k<=m;k++)
			{
				dp[i][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
				dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
				dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k]);
				if (s[i]==s[j]) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k]+2);
				else if (k>0) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k-1]+2);
			}
		}
	}
	// for (int len=1;len<=n;len++)
	// {
	// 	for (int i=1;i<=n-len+1;i++)
	// 	{
	// 		int j=i+len-1;
	// 		for (int k=0;k<=m;k++)
	// 		{
	// 			printf("%d %d %d: %d\n",i,j,k,dp[i][j][k]);
	// 		}
	// 	}
	// }
	int ans=0;
	for (int k=0;k<=m;k++) ans=max(ans,dp[1][n][k]);
	printf("%d\n",ans);
}