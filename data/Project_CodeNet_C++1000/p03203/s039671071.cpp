#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int h, w, n, x, y, res;
set<ii> st;
vii a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> h >> w >> n;

	res = h;

	while (n--) {
		cin >> x >> y;
		if (x >= y) a.emplace_back(x, y);
	}

	sort(all(a));

	int d = 0;
	for (int i = 0; i < a.size(); i++) {
		x = a[i].fi, y = a[i].se;

		if (x - y > d && !st.count(ii(x, y))) res = min(res, x - 1);
		if (x - y == d) d++;
		st.emplace(x+1, y);
	}

	cout << res << endl;

	return 0;
}