#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> dp, scores;
vector<int> rem;
const ll INF = 1e18;

void recursion(int r, int mask, ll score, int grp) {
	if (r == (int)rem.size()) {
		dp[mask] = max(dp[mask], score + scores[grp]);
		return;
	}
	recursion(r + 1, mask, score, grp);
	recursion(r + 1, mask ^ (1 << rem[r]), score, grp ^ (1 << rem[r]));
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	scores.resize(1 << n, 0);
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (int j = i + 1; j < n; j++) {
					if (mask & (1 << j)) {
						scores[mask] += a[i][j];
					}
				}
			}
		}
	}
	dp.resize(1 << n, -INF);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		rem.clear();
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) {
				rem.push_back(i);
			}
		}
		recursion(0, mask, dp[mask], 0);
	}
	cout << dp[(1 << n) - 1];

	return 0;
}