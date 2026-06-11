#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen(".in.txt", "r", stdin);
	// freopen(".out.txt", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ii; cin >> n >> m;
	vector<int> c = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<bool> can(10);
	vector<vector<int>> dp(5001, vector<int> (n + 1, -1));
	dp[0][0] = 0;
	for(int i = 0; i < m; i++)
	{
		int a; cin >> a;
		can[a] = 1;
	}
	for(int i = 1; i < 5001; i++) for(int j = 0; j < n + 1; j++) for(int k = 9; k; k--)
		if(can[k] && j - c[k] > -1 && dp[i - 1][j - c[k]] != -1)
	{
		dp[i][j] = k;
		break;
	}
	for(int i = 5000; i > -1; i--) if(dp[i][n] != -1)
	{
		ii = i;
		break;
	}
	for(int i = ii; i; i--)
	{
		cout << dp[i][n];
		n -= c[dp[i][n]];
	}

	return 0;
}