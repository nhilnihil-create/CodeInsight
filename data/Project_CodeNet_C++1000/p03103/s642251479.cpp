#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	vector<pair<ll, ll>> pa;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		pa.push_back({ a,b });
	}
	sort(pa.begin(), pa.end());
	ll cnt = m;
	ll ans = 0;
	for (ll i = 0; i < pa.size(); i++) {
		if (pa[i].second <= cnt) {
			ans += pa[i].second * pa[i].first;
			cnt -= pa[i].second;
		}
		else {
			ans += cnt * pa[i].first;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}