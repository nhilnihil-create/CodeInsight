#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, k; cin >> n >> k;
	vector<ll> x(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	ll ans = 9223372036854775807LL;
	for (ll left = 0; left <= n - k ; left++) {
		ll right = left + k - 1;
		ll tmpL = abs(x[left]) + abs(x[right] - x[left]);
		ll tmpR = abs(x[right]) + abs(x[right] - x[left]);
		ll tmp = min(tmpL, tmpR);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}