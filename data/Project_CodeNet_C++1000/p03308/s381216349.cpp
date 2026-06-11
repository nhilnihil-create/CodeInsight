#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			ll tmp = abs(a[i] - a[j]);
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;
	return 0;
}