#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define M 1000000007
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, i, j, wt, m;
	
	cin >> n >> m;
	vector<string> v(n);
	vector<vector<int>> dp(n, vector<int> (m));
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	dp[0][0] = 1;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(i == 0 && j == 0)
				continue;
			if(i == 0)
			{
				if(v[i][j] == '#')
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i][j-1] ;
			}
			else if(j == 0)
			{
				if(v[i][j] == '#')
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j] ;
			}
		}
	}

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < m; j++)
		{
			if(v[i][j] == '#')
				dp[i][j] = 0;
			else
				dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % M;
		}
	}
	
	cout << dp[n-1][m-1] << endl;
	
}
