#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
ll n, a[MX], b[MX], x[MX], y[MX], res;

ll find (ll k) {
	return lower_bound(y, y + n, k) - y;
}

ll solve (int j) {
	ll res = 0;
	sort(y, y + n);

	forn (i, n) {
		res += find((1ll << j + 1) - x[i]);
		res -= find((1ll << j) - x[i]);

		res += find((1ll << j + 2) - x[i]);
		res -= find((1ll << j + 1) + (1ll << j) - x[i]);
	}

	return res % 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];

	forn (j, 29) {
		forn (i, n) x[i] = a[i] & ((1 << j + 1) - 1);
		forn (i, n) y[i] = b[i] & ((1 << j + 1) - 1);
		
		res |= solve(j) << j;
	}

	cout << res << endl;

	return 0;
}