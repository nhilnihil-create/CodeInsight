#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a), t(b);
	rep(i, a) cin >> s[i];
	rep(i, b) cin >> t[i];
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	rep(_, q) {
		ll x;
		cin >> x;
		vector<ll> cs, ct;
		auto its = lower_bound(s.begin(), s.end(), x);
		auto itt = lower_bound(t.begin(), t.end(), x);
		if (its != s.end()) cs.push_back(*its);
		if (itt != t.end()) ct.push_back(*itt);
		if (its != s.begin()) cs.push_back(*(its-1));
		if (itt != t.begin()) ct.push_back(*(itt-1));
		ll ans = 1001001001001001001LL;
		for(auto p: cs) for(auto q: ct) {
			if (p <= x && q <= x || p >= x && q >= x) {
				chmin(ans, max(abs(x-p), abs(x-q)));
			} else {
				chmin(ans, min(abs(x-p), abs(x-q)) + abs(p - q));
			}
		}
		cout << ans << endl;
	}
}
