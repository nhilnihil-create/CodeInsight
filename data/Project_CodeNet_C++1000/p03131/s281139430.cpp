#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ll k, a, b;
	cin >> k >> a >> b;
	ll ans;
	if (a + 2 <= b) {
		ll q = (k - a + 1) / 2;
		ll r = k - (a - 1 + 2 * q);
		ans = a + (b - a) * q + r;
	}
	else {
		ans = k + 1;
	}
	cout << ans << endl;
	return 0;
}