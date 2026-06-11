#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> v;
	for (ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	ll Min = v[0].second;
	ll ans = 1;
	for (ll i = 1; i < m; ++i) {
		if (Min <= v[i].first) {
			++ans;
			Min = v[i].second;
		}
		else {
			Min = min(Min, v[i].second);
		}
	}
	cout << ans << endl;
}
