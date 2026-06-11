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

const int MX = 200005;
int n;
ii a[MX];
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> a[i].fi >> a[i].se;
	sort(a, a+n, [&] (ii& i, ii& j) {
		return i.fi - i.se < j.fi - j.se;
	});

	if (a[0].fi == a[0].se) {
		cout << 0 << endl;
		return 0;
	}

	ll res = 0;
	int mn = 1e9;
	forn(i, n) {
		res += a[i].fi;
		if (a[i].fi > a[i].se)
			mn = min(mn, a[i].se);
	}
	cout << res - mn << endl;

	return 0;
}
