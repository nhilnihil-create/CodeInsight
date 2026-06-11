#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
	ll n, y; cin >> n >> y;
	bool end = false;
	ll ans1 = -1;
	ll ans2 = -1;
	ll ans3 = -1;
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			ll k = n - i - j;
			if (k < 0) continue;
			if (10000 * i + 5000 * j + 1000 * k == y) {
				ans1 = i;
				ans2 = j;
				ans3 = k;
				end = true;
				break;
			}
		}
		if (end) break;
	}
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}