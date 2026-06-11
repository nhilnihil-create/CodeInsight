#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const long long MOD=1e9+7;
int n;
long long dp[3005][3005],ans;
char str[N];

int main()
{
	scanf("%d%s",&n,str);
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(str[i-2]=='<')
		{
			for(int j=2;j<=i;j++)
			{
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
			}
		}
		else
		{
			for(int j=i-1;j>=1;j--)
			{
				dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++) ans=(ans+dp[n][i])%MOD;
	printf("%lld\n",ans);
}