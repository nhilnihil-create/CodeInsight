#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 5005;
int n, a[N], dp[N][N][2], pos[N], A, B;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> A >> B;
	fw (i, 0, n) {
		cin >> a[i], a[i]--;
		pos[a[i]] = i;
	}
	memset(dp, 63, sizeof dp);
	dp[0][0][0] = 0;
	fw (i, 0, n) fw (j, 0, n + 1) fw (k, 0, 2) {
		//i - 1 was in segment j - 1...j, including j - 1. Was j - 1 filled?
		dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][k]);
		if (pos[i] == j - 1) {
			int cost = 0;
			if (k) cost = A;
			dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + cost);
		} else if (pos[i] >= j) {
			dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + B);
		} else if (pos[i] < j - 1) {
			dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + A);
		}
	}
	int ans = infll;
	fw (j, 0, n + 1) fw (k, 0, 2) ans = min(ans, dp[n][j][k]);
	cout << ans;
	return 0;
}