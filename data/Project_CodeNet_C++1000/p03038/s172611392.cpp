#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	vector<pair<ll, ll>> pa;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		pa.push_back({ a,1 });
	}
	for (ll i = 0; i < m; i++) {
		ll b, c; cin >> b >> c;
		pa.push_back({ c,b });
	}
	sort(pa.begin(), pa.end(), greater<pair<ll, ll>>());
	ll ans = 0;
	ll cnt = 0;
	while (true) {
		if (pa[cnt].second <= n) {
			ans += pa[cnt].first * pa[cnt].second;
			n -= pa[cnt].second;
		}
		else {
			ans += pa[cnt].first * n;
			break;
		}		
		cnt++;
	}
	cout << ans << endl;
	return 0;
}