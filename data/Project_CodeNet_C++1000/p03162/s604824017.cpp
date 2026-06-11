#include <bits/stdc++.h>
#define ll long long
#define M 1000000007 
#define MM 998244353
#define PI 3.14159265 
using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<vector<int> > v( n , vector<int> (3));
	vector<vector<int> > dp( n , vector<int> (3));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
			dp[i][j] = 0;
		}
	}

	for (int i = 0 ; i < 3; i++)
	{
		dp[0][i] = v[0][i];
	} 

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				dp[i][j] = max(dp[i-1][1], dp[i-1][2]) + v[i][j];
			}
			else if (j == 1)
			{
				dp[i][j] = max(dp[i-1][0], dp[i-1][2]) + v[i][j];
			}
			else if (j == 2)
			{
				dp[i][j] = max(dp[i-1][0], dp[i-1][1]) + v[i][j];
			}
		}
	}

	int ans = max(dp[n-1][0], dp[n-1][1]);
	ans = max (ans, dp[n-1][2]);
	cout << ans;

  	return 0;
}