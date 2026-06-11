#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll a, b, k;
	cin >> a >> b >> k;

	while (k > 0) {
		a /= 2;
		b += a;
		--k;
		if (k <= 0) { break; }
		b /= 2;
		a += b;
		--k;
	}
	cout << a << " " << b << endl;

	return 0;
}
