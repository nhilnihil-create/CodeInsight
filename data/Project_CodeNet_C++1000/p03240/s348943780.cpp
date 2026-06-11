#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
const ll MOD = 998244353;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0}, dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int x[n], y[n], h[n];
	int X, Y, H;
	rep(i, n) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] != 0) X = x[i], Y = y[i], H = h[i];
	}
	rep(i, 101) {
		rep(j, 101) {
			int T = H + abs(i - X) + abs(j - Y);
			bool ch = 1;
			rep(k, n) {
				if (max(T - abs(i - x[k]) - abs(j - y[k]), 0LL) != h[k]) {
					ch = 0;
					break;
				}
			}
			if (ch) {
				cout << i << " " << j << " " << T << endl;
				return 0;
			}
		}
	}
	return 0;
}