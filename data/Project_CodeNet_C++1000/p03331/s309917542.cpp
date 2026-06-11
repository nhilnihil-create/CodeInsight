#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll ans = 1000000;
	for (int i = 1; i <= n / 2; i++) {
		ll a = i;
		ll b = n - a;
		ll res = 0;
		while (a > 0) {
			res += a % 10;
			a /= 10;
		}
		while (b > 0) {
			res += b % 10;
			b /= 10;
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}