#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int int_Inf = 2147483647;
const ll ll_Inf = 9223372036854775807LL;

int main() {

	ll n, k; cin >> n >> k;
	vector<ll> x(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	ll ans = ll_Inf;
	for (ll i = 0; i < n - k + 1; i++) {
		ll tmpAns;
		ll left = x[i];
		ll right = x[i + k - 1];

		if (abs(left) <= abs(right)) {
			tmpAns = abs(left);
		}
		else {
			tmpAns = abs(right);
		}
		tmpAns += right - left;
		ans = min(ans, tmpAns);
	}
	cout << ans << endl;
	return 0;
}