#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

#ifdef LOCAL
#include "/Users/swad/Desktop/CP/debug.h"
#endif

// const int N = int(1e5) + 10;
const int MOD = int(1e9) + 7;

int n;
string s;
vector<vector<int>> dp;

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	cin >> n >> s;

	dp = vector<vector<int>>(n, vector<int>(n, 0));
	dp[n - 1][0] = 1;

	for (int i = n - 2; i >= 0; i--) {
		int st, en, inc;
		if (s[i] == '>') st = 1, en = n - i, inc = 1;
		else st = n - i - 2, en = -1, inc = -1;

		for (int d = st; d != en; d += inc) {
			dp[i][d] = dp[i][d - inc] + dp[i + 1][d - (inc == 1)];
			if (dp[i][d] > MOD) dp[i][d] -= MOD;
		}
	}

	int ans = 0;
	for (int d = 0; d < n; d++) {
		ans += dp[0][d];
		if (ans > MOD) ans -= MOD;
	}

	cout << ans << endl;

	return 0;
}