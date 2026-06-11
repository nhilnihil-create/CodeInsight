#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	vector<ll> x(m);
	for (ll i = 0; i < m; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	vector<ll> dist(m - 1);
	for (ll i = 0; i < m - 1; i++) {
		dist[i] = x[i + 1] - x[i];
	}
	sort(dist.rbegin(), dist.rend());
	ll cnt = n - 1;
	ll ans = 0;
	for (ll i = 0; i < m - 1; i++) {
		if (0 < cnt) {
			cnt--;
			continue;
		}		
		ans += dist[i];
	}
	cout << ans << endl;
	return 0;
}