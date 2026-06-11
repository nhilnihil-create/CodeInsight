// Problem : C - Candies
// Contest : AtCoder Regular Contest 090
// URL : https://atcoder.jp/contests/arc090/tasks/arc090_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n = 2, m, a[3][N], dp[3][N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(i > 1 ? dp[i - 1][j] : 0, j > 1 ? dp[i][j - 1] : 0);
			dp[i][j] += a[i][j];
		}
	}
	cout << dp[n][m];
}
