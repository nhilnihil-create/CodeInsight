#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
	ll n, h; cin >> n >> h;
	vector<pair<ll, ll>> pa;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		pa.push_back({ a,-1 });
		pa.push_back({ b,1 });
	}
	sort(pa.rbegin(), pa.rend());
	ll ans = 0;
	ll index = 0;
	while (0 < h) {
		if (pa[index].second == -1) {
			if (h % pa[index].first == 0) {
				ans += h / pa[index].first;
			}
			else {
				ans += h / pa[index].first + 1;
			}
			break;
		}
		else {
			h -= pa[index].first;
			index++;
		}
		ans++;
	}
	cout << ans << endl;
    return 0;
}