#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define int long long
#define mod 1000000007

int dp[105][100005];

int solve1(int* a, int i, int k, int n) {
	if (k < 0)return 0;
	if (k == 0)return 1;
	if (i > n)return 0;
	if (dp[i][k] != -1)return dp[i][k];
	dp[i][k] = (mod + solve1(a, i, k - 1, n) + solve1(a, i + 1, k, n) - solve1(a, i + 1, k - a[i] - 1, n)) % mod;
	return dp[i][k];
}

void solve() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	int a[n + 1];
	int i;
	for (i = 1; i <= n; i++)cin >> a[i];

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)dp[i][0] = 1;
	for (i = 1; i <= k; i++)dp[0][i] = 0;
	int len = solve1(a, 1, k, n);
	cout << len << endl;
	return;
}


int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}