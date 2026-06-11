#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	bool ok = true;
	for (ll a = 0; a < n; a++) {
		if (a * m % n) {
			continue;
		}
		if (s[a] != t[a * m / n]) {
			ok = false;
		}
	}

	if (ok) {
		cout << lcm(n, m) << endl;
	}
	else {
		cout << -1 << endl;
	
	}

	return 0;
}
