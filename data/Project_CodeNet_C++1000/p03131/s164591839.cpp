#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll k, a, b; cin >> k >> a >> b;
	ll ans = 0;
	if (a + 1 < b) {
		ll quo = k / (a + 1);
		ll mod = k % (a + 1);
		if (quo == 0) {
			ans = 1;
			ans += k;
		}
		else { // 1 <= quo
			k -= a + 1;
			ans = b;
			ll quo2 = k / 2;
			ll mod2 = k % 2;
			ans -= quo2 * a;
			ans += quo2 * b;
			ans += mod2;
		}
	}
	else {
		ans = 1;
		ans += k;
	}
	cout << ans << endl;
	return 0;
}