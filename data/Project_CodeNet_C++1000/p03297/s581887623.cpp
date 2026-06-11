#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b, c, d; 
	cin >> a >> b >> c >> d;
	if (a < b) cout << "No\n";
	else if (c <= b) {
		long long e = __gcd(b, d);
		a %= e;
		long long f = a / e * e;
		long long g = (b - a - 1) / e * e;
		long long mn = a - f, mx = a + g;
		if (mn + d < b || mx > c) cout << "No\n";
		else cout << "Yes\n"; 
	}
	else {
		if (d >= b) cout << "Yes\n"; else cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t; while (t--) solve();
}