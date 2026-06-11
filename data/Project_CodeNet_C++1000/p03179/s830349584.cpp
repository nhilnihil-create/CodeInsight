#include<bits/stdc++.h>
using namespace std;
const int N=3005,mod=1e9+7;
int dp[N][N],n,ans;
char s[N];
int main()
{
	scanf("%d%s",&n,s+1);
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
		for(int j=1;j<=i;j++)
		{
			if(s[i]=='<')
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
			else
			{
				dp[i+1][0]=(dp[i+1][0]+dp[i][j])%mod;
				dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j]+mod)%mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=(ans+dp[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}