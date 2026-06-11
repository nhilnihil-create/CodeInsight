#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	ll gcd = __gcd(n, m);
	ll lcm = (n * m) / gcd;
	n /= gcd;
	m /= gcd;
	for (int i = 0; i < gcd; i++) {
		if (s[i * n] != t[i * m]) {
			return cout << "-1", 0;
		}
	}
	cout << lcm << endl;
	return 0;

}
