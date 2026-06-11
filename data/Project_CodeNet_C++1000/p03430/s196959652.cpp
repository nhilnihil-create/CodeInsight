#include <bits/stdc++.h>

#define F firts
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

const int N = 310;

int dp[N][N][N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.size(), k;
	cin >> k;

	for(int i=0; i<n; i++)
		for(int j=0; j<=k; j++)
			dp[i][i + 1][j] = 1;

	for(int c=0; c<=k; c++)
		for(int len=2; len<=n; len++)
			for(int l=0; l+len<=n; l++)
			{
				int r = l + len;
				dp[l][r][c] = max(dp[l][r - 1][c], dp[l + 1][r][c]);
				if(s[l] == s[r - 1])dp[l][r][c] = max(dp[l][r][c], 2 + dp[l + 1][r - 1][c]);
				else if(c >= 1)dp[l][r][c] = max(dp[l][r][c], 2 + dp[l + 1][r - 1][c - 1]);
			}

	cout << dp[0][n][k] << endl;

}