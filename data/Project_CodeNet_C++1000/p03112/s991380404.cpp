#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

int main() {
	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a), t(b);
	for (ll i = 0; i < a; i++) cin >> s[i];
	for (ll i = 0; i < b; i++) cin >> t[i];
	while (q--) {
		ll x;
		cin >> x;
		ll ans = INF;
		auto itr1 = lower_bound(ALL(s), x);
		auto itr2 = lower_bound(ALL(t), x);
		if (itr1 != s.end() && itr2 != t.end()) {
			ans = min(ans, max(*itr1, *itr2) - x);
		}
		auto itr3 = upper_bound(ALL(s), x);
		auto itr4 = upper_bound(ALL(t), x);
		if (itr3 != s.begin() && itr4 != t.begin()) {
			ans = min(ans, x - min(*(itr3 - 1), *(itr4 - 1)));
		}
		if (itr1 != s.end() && itr4 != t.begin()) {
			ans = min(
				ans,
				(*itr1 - *(itr4 - 1)) * 2 - max(*itr1 - x, x - *(itr4 - 1))
			);
		}
		if (itr2 != t.end() && itr3 != s.begin()) {
			ans = min(
				ans,
				(*itr2 - *(itr3 - 1)) * 2 - max(*itr2 - x, x - *(itr3 - 1))
			);
		}
		cout << ans << '\n';
	}
}