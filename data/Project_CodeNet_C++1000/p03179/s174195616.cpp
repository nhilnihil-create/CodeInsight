#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MOD 1000000007
#define MAX 3005
int dp[MAX][MAX];
signed main()
{
	int n,i,j;
	cin>>n;
	string s;
	cin>>s;
	dp[0][1]=1;
	for(i=1;i<n;i++)
	{
		dp[i][0]=0;
		dp[i][n+1]=0;
		if(s[i-1]=='<')
		for(j=1;j<=i+1;j++)
		{
			if(dp[i-1][j-1]>0||dp[i][j-1]>0)
			dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
		}
		if(s[i-1]=='>')
		for(j=i+1;j>=1;j--)
		{
			if(dp[i-1][j]>0||dp[i][j+1]>0)
			dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
		}
	
	}
	int x=0;
	for(j=1;j<=n;j++)
	x=(x+dp[n-1][j])%MOD;
	cout<<x<<"\n";

}