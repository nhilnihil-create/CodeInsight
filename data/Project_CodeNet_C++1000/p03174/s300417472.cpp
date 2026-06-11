#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int n;
vector<vector<int>> a, dp;

int recursion(int m, int w) {
	if (m == n) {
		if (w == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[m][w] != -1)
		return dp[m][w];
	ll total = 0;
	for (int i = 0; i < n; i++) {
		int cur = 1 << i;
		bool avail = (((cur & w) == 0) ? 0 : 1);
		if (avail && a[m][i]) {
			total = (total + recursion(m + 1, cur ^ w)) % mod;
		}
	}
	return dp[m][w] = total;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	a.resize(n, vector<int> (n));
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(1 << n, -1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int answer = recursion(0, (1 << n) - 1);
	cout << answer;

	return 0;
}