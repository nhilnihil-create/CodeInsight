#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s;
	cin >> t;
	ll l = n / __gcd(n, m) * m;
	ll nl = l / m;
	ll ml = l / n;
	for (int i = 0; i < n / nl; i++) {
		if (s.at(i * nl) != t.at(i * ml)) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << endl;
}