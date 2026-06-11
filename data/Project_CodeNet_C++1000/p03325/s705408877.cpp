#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		while (true) {
			if (a[i] % 2 == 0 && a[i] / 2 != 0) {
				ans++;
				a[i] /= 2;
			}
			else {
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}