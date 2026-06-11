#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = 0;
	for (ll i = 1; i <= n; ++i) {
		ll p = i;
		ll sum = 0;
		while (p > 0) {
			sum += p % 10;
			p /= 10;
		}
		if (sum >= a && sum <= b) {
			ans += i;
		}
	}
	cout << ans;
}
