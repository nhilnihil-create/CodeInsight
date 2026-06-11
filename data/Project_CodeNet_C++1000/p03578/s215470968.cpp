#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
using ll = long long;
using namespace std;
signed main() {
	ll n, m; cin >> n;
	map<ll, ll> M;
	rep(i, n) { ll a; cin >> a; M[a]++; }
	cin >> m;
	rep(i, m) {
		ll a; cin >> a;
		if (M[a] > 0) { M[a]--; }
		else { cout << "NO\n"; return 0; }
	}
	cout << "YES\n";
	return 0;
}