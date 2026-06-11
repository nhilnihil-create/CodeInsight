#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct frac {
	// p/q
	ll p;
	ll q;
};
ll gcd(ll x, ll y) {
	ll r;
	while ((r = x % y) != 0) {
		x = y;
		y = r;
	}
	return y;
}
ll lcm(ll x, ll y) {
	return (x / gcd(x, y) * y);
}
int main() {
	ll n;
	cin >> n;
	frac num = {4, n};
	for (ll a = 1; a <= 3500; a++) {
		for (ll b = 1; b <= 3500; b++) {
			frac x;
			ll l = lcm(n, lcm(a, b));
			x.q = l;
			x.p = num.p * l / num.q - l / a - l / b;
			if (x.p <= 0 || x.q / x.p < 0) {
				continue;
			}
			if (x.q % x.p == 0) {
				cout << a << " " << b << " " << x.q / x.p << endl;
				return 0;
			}
		}
	}
	return 0;
}