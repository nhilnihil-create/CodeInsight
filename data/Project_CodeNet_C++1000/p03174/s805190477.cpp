#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int n;
const int N = 22;
int mat[N][N];

int dp[N][(1 << 22)];

int solve(int row, int avail)
{
	if (row == n)
	{
		return avail == 0;
	}

	int & ans = dp[row][avail];
	if (ans != -1) return ans;

	ans = 0;

	for (int c = 0; c < n; c++)
	{
		if (mat[row][c] && (avail & (1 << c)))
		{
			int mask = ~(1 << c);
			ans += solve(row + 1, avail & mask);
			ans %= MOD;
		}
	}

	return ans;

}


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FASTIO;

	cin >> n;

	for (int i  = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {

			cin >> mat[i][j];
		}
	}

	memset(dp, -1, sizeof dp);

	int ans = solve(0, (1 << n) - 1);
	cout << ans;

}