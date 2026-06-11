#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> num_ways(n + 1, vector<int> (k + 1, 0));
	for (int i = 0; i <= n; i++) {
		num_ways[i][0] = 1;
	}
	num_ways[0][0] = 1;
	for (int j = 1; j <= k; j++) {
		num_ways[0][j] = 0;
	}
	vector<int> prev_prefix(k + 1, 0);
	prev_prefix[0] = num_ways[0][0];
	for (int i = 1; i <= k; i++) {
		prev_prefix[i] = prev_prefix[i - 1] + num_ways[0][i];
		prev_prefix[i] %= MOD;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			num_ways[i][j] += prev_prefix[j];
			num_ways[i][j] %= MOD;
			if (max(j - a[i - 1], 0ll) - 1 >= 0) {
				num_ways[i][j] -= prev_prefix[max(j - a[i - 1], 0ll) - 1];
				if (num_ways[i][j] < 0) {
					num_ways[i][j] += MOD;
				}
			}
		}
		prev_prefix[0] = num_ways[i][0];
		for (int pos = 1; pos <= k; pos++) {
			prev_prefix[pos] = prev_prefix[pos - 1] + num_ways[i][pos];
			prev_prefix[pos] %= MOD;
		}
	}
	cout << num_ways[n][k] << endl;

	return 0;
}