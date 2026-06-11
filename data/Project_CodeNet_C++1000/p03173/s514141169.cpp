#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> prefix_sum;

int range_sum(int l, int r) {
	int res = prefix_sum[r];
	if (l > 0) res -= prefix_sum[l - 1];
	return res;
}

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {

	// }
	int n; cin >> n;
	vector<int> a(n); int sum = 0;
	prefix_sum.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	prefix_sum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + a[i];
	}
	vector<vector<int>> min_cost(n, vector<int> (n, LLONG_MAX));
	for (int i = 0; i < n; i++) {
		min_cost[i][i] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j - 1; k++) {
				min_cost[i][j] = min(min_cost[i][j], range_sum(i, j) + min_cost[i][k] + min_cost[k + 1][j]);
			}
		}
	}
	cout << min_cost[0][n - 1] << endl;

	return 0;
}