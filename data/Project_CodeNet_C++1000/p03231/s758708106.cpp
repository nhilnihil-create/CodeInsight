#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

int main() {
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	bool ok = true;
	for (ll i = 0; i < n; i++) {
		if (i * m % n) {
			continue;
		}
		if (s[i] != t[i * m / n]) {
			ok = false;
		}
	}
	
	if (ok) {
		cout << lcm(m, n) << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}
