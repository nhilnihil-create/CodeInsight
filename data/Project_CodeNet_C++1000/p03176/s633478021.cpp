#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;





void solve() {
	int n;
	cin >> n;
	vector<int> h(n), a(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int base = 1;
	while (base <= n) {
		base *= 2;
	}
	vector<ll> tree(2 * base);


	vector<ll> dp(n + 1);
	for (int i = 0; i < n; i++) {
		// max dp[j] for j in [0, h[i] - 1]

		int x = h[i] + base;
		ll best = 0;
		while (x > 1) {
			if (x % 2 == 1) {
				best = max(best, tree[x - 1]);
			}
			x /= 2;
		}

		dp[h[i]] = best + a[i];

		for (int j = base + h[i]; j >= 1; j /= 2) {
			tree[j] = max(tree[j], dp[h[i]]);
		} 

		// for (int j = 0; j < h[i]; j++) {
		// 	dp[h[i]] = max(dp[h[i]], dp[j] + a[i]);
		// }
	}


	ll res = -1;
	for (int i = 0; i <= n; i++) {
		res = max(res, dp[i]);
	}

	cout << res << endl;
}

int main() {
    FAST_INPUT;

    solve();
    return 0;
}
