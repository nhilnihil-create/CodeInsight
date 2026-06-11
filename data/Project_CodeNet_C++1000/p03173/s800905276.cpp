#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long
#define inf (1LL<<60)

int dp[500][500];


int slimes(int i, int j, vector<int> &cs) {
	int n = cs.size() - 1;
	if (i >= n || j >= n || i < 0 || j < 0)return 0;
	if (j <= i)dp[i][j] = 0;
	if (dp[i][j] != -1)return dp[i][j];
	int val = inf;
	int k;
	for (k = i; k < j; k++) {
		val = min(val, slimes(i, k, cs) + slimes(k + 1, j, cs));
	}
	return dp[i][j] = cs[j + 1] - cs[i] + val;
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	int i, j;
	for (i = 0; i < n; i++)cin >> a[i];
	vector<int> cs(n + 1);
	cs[0] = 0;
	for (i = 1; i <= n; i++)cs[i] = cs[i - 1] + a[i - 1];

// 	for (i = 0; i <= n; i++)cout << cs[i] << " ";
// 	cout << endl;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)dp[i][j] = -1;
	}

	cout << slimes(0, n - 1, cs);
	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}