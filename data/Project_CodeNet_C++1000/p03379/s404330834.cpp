#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int x[n], y[n];
	rep(i, n) {
		cin >> x[i];
		y[i] = x[i];
	}
	sort(y, y + n);
	int p = y[n / 2 - 1], q = y[n / 2];
	rep(i, n) {
		if (x[i] <= p)
			cout << q << endl;
		else
			cout << p << endl;
	}
	return 0;
}