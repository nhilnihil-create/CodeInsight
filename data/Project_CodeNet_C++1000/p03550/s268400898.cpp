#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
ll dp[2][100005];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, z, w;
	cin >> n >> z >> w;
	int a[n];
	rep(i, n) cin >> a[i];
	int ans = abs(a[n - 1] - w);
	for (int i = n - 2; i >= 0; i--) {
		int now = abs(a[n - 1] - a[i]);
		for (int j = i + 1; j < n - 1; j++) now = min(now, abs(a[n - 1] - a[j]));
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}