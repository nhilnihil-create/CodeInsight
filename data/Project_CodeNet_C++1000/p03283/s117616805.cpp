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
int a[505][505];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		a[l][r]++;
	}
	rep(i, 505) rep(j, 504) a[i][j + 1] += a[i][j];
	rep(i, 505) rep(j, 504) a[j + 1][i] += a[j][i];
	rep(i, q) {
		int p, q;
		cin >> p >> q;
		cout << a[q][q] - a[p - 1][q] - a[q][p - 1] + a[p - 1][p - 1] << endl;
	}
	return 0;
}