#include <bits/stdc++.h>              
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x, n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair< int, int > P;
typedef pair< int, P > PP;

//-------------------------------------------------

int t;
ll a, b, c, d;

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d;
		if (a < b || d < b) {
			cout << "No" << endl;
			continue;
		}
		if (c >= b - 1) {
			cout << "Yes" << endl;
			continue;
		}
        ll g = gcd(b, d);
		ll l = ((c + 1 - a) % b + b) % b;
		ll r = ((b - a - 1) % b + b) % b;
		if (l <= r) {
			ll tmp = g * (l / g + !!(l % g));
			if (l <= tmp && tmp <= r) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}

	return 0;
}

