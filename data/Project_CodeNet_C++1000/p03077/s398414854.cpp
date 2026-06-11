#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {

	ll n; cin >> n;
	const ll p = 5;
	vector<ll> c(p);
	ll minIndex;
	ll minValue = 9223372036854775807LL;
	ll ans = 4;
	for (ll i = 0; i < p; i++) {
		cin >> c[i];
		if (chmin(minValue, c[i])) {
			minIndex = i;
		}
	}
	ans += (n + minValue - 1) / minValue;
	cout << ans << endl;
	return 0;
}