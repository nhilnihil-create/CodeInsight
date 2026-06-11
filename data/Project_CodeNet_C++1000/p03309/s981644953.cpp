#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		ll tmp; cin >> tmp;
		a[i] = tmp - (i + 1);
	}
	sort(a.begin(), a.end());
	ll solution;
	if (n % 2 == 0) {
		solution = a[n / 2 - 1];
	}
	else {
		solution = a[n / 2];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - solution);
	}
	cout << ans << endl;
	return 0;
}