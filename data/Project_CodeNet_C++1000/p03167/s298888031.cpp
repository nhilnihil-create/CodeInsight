#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main()
{
	int h,w;
	string str[1001];
	int dp[1001][1001];
	cin >> h >> w;
	for(int i=0;i<h;i++)
		cin >> str[i];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<h;i++)
	{
		if(str[0][i]=='.')
			dp[0][i] = 1;
		else
			break;
	}
	for(int i=0;i<w;i++)
	{
		if(str[i][0] == '.')
			dp[i][0] = 1;
		else
			break;
	}
	for(int i=1;i<h;i++)
	{
		for(int j=1;j<w;j++)
		{
			if(str[i][j]=='.')
				dp[i][j] = (dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
			else
				dp[i][j] = 0;
		}
	}
	cout << dp[h-1][w-1] << "\n";
}

