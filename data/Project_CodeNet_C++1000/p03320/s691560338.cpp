#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; ++ i)

using namespace std;

typedef long long ll;

inline int c(ll x) {
	int res = 0;
	while (x) res += x % 10, x /= 10;
	return res;
}

inline ll f(ll x) {
	double mn = 1.0 * x / c(x); ll res = x;
	for (ll d = 1; d <= x; d *= 10) {
		ll nw = x / d * d + d * 10 - 1;
		double t = 1.0 * nw / c(nw);
		if (t < mn) res = nw, mn = t;
	}
	return res;
}

int main() {

	int k; cin >> k;
	
	for (ll nw = 1; k --; nw = f(nw + 1)) printf("%lld\n", nw);

	return 0;
}
