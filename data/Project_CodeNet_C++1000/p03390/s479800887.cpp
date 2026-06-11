#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 2 * a - 2 << endl;
		} else {
			ll i = 0, j = 2e9+5, rep = 35;
			while (rep--) {
				ll m = (i + j) / 2;
				if (m * m >= a * b) j = m;
				else i = m;
			}
			j--;

			if (j * (j + 1) < a * b) cout << 2 * j - 1 << endl;
			else cout << 2 * j - 2 << endl;
		}
	}

	return 0;
}