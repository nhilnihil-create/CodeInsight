#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e6;

int main() {
	ll n;
	cin >> n;
	map<ll, ll> m;
	for (ll i = 0; i < n; ++i) {
		ll p;
		cin >> p;
		if (m[p - 1] > 0) {
			m[p] = m[p - 1] + 1;
		}
		else {
			m[p] = 1;
		}
	}
	ll ans = 0;
	for (auto p : m)ans = max(ans, p.second);
	cout << n - ans << endl;
}
