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
	set<ll> s;
	ll ans = 1;
	s.insert(v[0].second);
	for (ll i = 1; i < m; ++i) {
		if (*s.begin() <= v[i].first) {
			++ans;
			s.clear();
			s.insert(v[i].second);
		}
		else {
			s.insert(v[i].second);
		}
	}
	cout << ans << endl;
}
