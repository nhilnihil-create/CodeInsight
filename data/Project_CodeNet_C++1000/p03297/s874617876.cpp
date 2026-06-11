// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e5+9;
const ll mod = 1e9+7;

ll gcd (ll a, ll b) {
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	ll a, b, c, d, g;
	for (; T; T--) {
		cin >> a >> b >> c >> d;
		if (a < b || d < b) {
			cout << "No\n";
			continue;
		}
		if (c >= b) {
			cout << "Yes\n";
			continue;
		}
		a = a % b;
		d = d % b;
		g = b;
		if (a > c) {
			cout << "No\n";
			continue;
		}
		if (d)
			g = gcd(d, b);
		ll f = (c - a) / g * g + a;
		if (f + g < b)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}

