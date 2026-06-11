#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	int n, m;
	cin >> n >> m;
	ll x[n], y[n], z[n];
	rep(i, n) cin >> x[i] >> y[i] >> z[i];
	ll ans = 0;
	rep(bit, 8) {
		vector<pair<ll, ll>> vec;
		int a = bit & 1 ? 1 : -1, b = bit >> 1 & 1 ? 1 : -1, c = bit >> 2 & 1 ? 1 : -1;
		rep(i, n) vec.push_back({x[i] * a + y[i] * b + z[i] * c, i});
		sort(vec.begin(), vec.end());
		ll p = 0, q = 0, r = 0;
		rep(i, m) {
			p += x[vec[i].second] * a;
			q += y[vec[i].second] * b;
			r += z[vec[i].second] * c;
		}
		ans = max(ans, abs(p) + abs(q) + abs(r));
	}
	cout << ans << endl;
	return 0;
}