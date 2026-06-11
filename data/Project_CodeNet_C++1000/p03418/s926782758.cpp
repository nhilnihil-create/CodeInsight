#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, k; cin >> n >> k;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	ll ans = 0;
	for (ll i = 1; i <= n ; i++) {
		ll quo = n / i;
		ll mod = n % i;
		ans +=quo * max(0LL, i - k);
		ans += max(0LL, mod - k + 1);
	}
	cout << ans << endl;
    return 0;
}