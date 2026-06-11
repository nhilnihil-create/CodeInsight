#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007LL;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n=s.size();
	long long dp[n+5][4]={};
	dp[0][0]=1LL;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			dp[i+1][j]=dp[i][j];
		}
		if (s[i]=='A')
		{
			dp[i+1][1]+=dp[i][0];
			dp[i+1][1]%=mod;
		}
		else if (s[i]=='B')
		{
			dp[i+1][2]+=dp[i][1];
			dp[i+1][2]%=mod;
		}
		else if (s[i]=='C')
		{
			dp[i+1][3]+=dp[i][2];
			dp[i+1][3]%=mod;
		}
		else
		{
			dp[i+1][0]+=2*dp[i][0];
			dp[i+1][0]%=mod;
			dp[i+1][1]+=dp[i][0];
			dp[i+1][1]+=2*dp[i][1];
			dp[i+1][1]%=mod;
			dp[i+1][2]+=dp[i][1];
			dp[i+1][2]+=2*dp[i][2];
			dp[i+1][2]%=mod;
			dp[i+1][3]+=dp[i][2];
			dp[i+1][3]+=2*dp[i][3];
			dp[i+1][3]%=mod;
		}
	}
	cout<<dp[n][3]<<endl;
	return 0;
}
