#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 1LL << 60;

int main() {
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a + 2), t(b + 2);
	s[0] = t[0] = -INF;
	s[a + 1] = t[b + 1] = INF;
	REP(i, a) cin >> s[i];
	REP(i, b) cin >> t[i];
	rep(i, q) {
		ll x;
		cin >> x;
		auto itr1 = lower_bound(s.begin(), s.end(), x) - s.begin();
		auto itr2 = lower_bound(t.begin(), t.end(), x) - t.begin();
		ll sr = s[itr1];
		ll tr = t[itr2];
		ll sl = s[itr1 - 1];
		ll tl = t[itr2 - 1];
		ll ans;
		if (sl <= tl && sr <= tr) {
			ans = min(sr - x + min(sr - tl, tr - sr), x - tl + min(tl - sl, sr - tl));
		} else if (sl <= tl && tr <= sr) {
			ans = min(tr - x + min(sr - tr, tr - sl), x - tl + min(tl - sl, sr - tl));
		} else if (tl <= sl && sr <= tr) {
			ans = min(sr - x + min(tr - sr, sr - tl), x - sl + min(sl - tl, tr - sl));
		} else {
			ans = min(tr - x + min(sr - tr, tr - sl), x - sl + min(sl - tl, tr - sl));
		}
		cout << ans << endl;
	}
	return 0;
}