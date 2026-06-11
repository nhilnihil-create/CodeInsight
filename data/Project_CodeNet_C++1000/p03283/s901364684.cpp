#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, m, q;
	cin >> n >> m >> q;
	vector<ll> l(m), r(m);
	for (ll i = 0; i < m; i++) cin >> l[i] >> r[i];
	vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
	for (ll i = 0; i < m; i++) v[l[i]][r[i]]++;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			v[i][j] += v[i][j - 1];
		}
	}
	for (ll j = 1; j <= n; j++) {
		for (ll i = 1; i <= n; i++) {
			v[i][j] += v[i - 1][j];
		}
	}
	while (q--) {
		ll p, q;
		cin >> p >> q;
		cout << v[q][q] - v[p - 1][q] << '\n';
	}
}