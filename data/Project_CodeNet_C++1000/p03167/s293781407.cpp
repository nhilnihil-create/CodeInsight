#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
const int mod = 1e9+7;

int32_t main()
{
	int n, m;
	cin >> n >> m;
	vector<string> in(n);
	rep(i, n)
	{
	    cin >> in[i];
	}
	int dp[n][m];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	rep(i, n)
	{
	    rep(j, m)
	    {
	        if(in[i][j] == '#')
	            continue;
	        if(i-1 >= 0)
	            dp[i][j] += dp[i-1][j];
	        if(j-1 >= 0)
	            dp[i][j] += dp[i][j-1];
	        dp[i][j] %= mod;
	    }
	}
// 	rep(i, n)
// 	{
// 	    rep(j, m)
// 	        cout << dp[i][j] << " ";
// 	    cout << "\n";
// 	}
	cout << dp[n-1][m-1];
  	return 0;
}