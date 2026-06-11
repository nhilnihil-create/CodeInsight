#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <complex>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int a, b, q; cin >> a >> b >> q;
	vector<ll> s(a), t(b);
	ll x = 0;
	rep(i, 0, a) cin >> s[i];
	rep(i, 0, b) cin >> t[i];
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	s.push_back(INF);
	t.push_back(INF);

	rep(i, 0, q) {
		ll ans = INF;
		cin >> x;
		ll al = upper_bound(s.begin(), s.end(), x) - s.begin();
		ll ar = upper_bound(s.begin(), s.end(), x) - s.begin();
		ll bl = upper_bound(t.begin(), t.end(), x) - t.begin();
		ll br = upper_bound(t.begin(), t.end(), x) - t.begin();
		--bl; --al;


		ll c = abs(x - (al < 0 ? INF : s[al]));
		ll d = abs(x - t[br]);
		ll e = abs(x - s[ar]);
		ll f = abs(x - (bl < 0 ? INF : t[bl]));

		ll k1 = c + d + min(c, d);
		ll k2 = max(c, f);
		ll k3 = max(d, e);
		ll k4 = f + e + min(f, e);
		ans = min(ans, min(k1, min(k2, min(k3, k4))));
		cout << ans << '\n';
	}
	return 0;
}
