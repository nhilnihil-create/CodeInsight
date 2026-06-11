#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll k, a, b;
	cin >> k >> a >> b;

	if (2 > (b - a)) {
		cout << k + 1 << '\n';
	} else {
		if (k < a - 1) {
			cout << k + 1 << '\n';
		} else {
			k -= (a - 1);
			ll x = a;
			x += (k / 2) * (b - a) + k % 2;
			cout << x << '\n';
		}
	}
	return 0;
}