#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[311];
int dp[311][311][311],K;
int main()
{
	scanf("%s%d",s,&K);int n=strlen(s);
	for(int i=n;i>=1;i--)s[i]=s[i-1];
	for(int i=1;i<=n;i++)dp[i][i][0]=1;
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=0;k<=min(len>>1,K);k++)
			{
				dp[i][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
				if(s[i]==s[j])dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k]+2);
				else if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k-1]+2);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=K;i++)ans=max(ans,dp[1][n][i]);
	printf("%d",ans);return 0;
}