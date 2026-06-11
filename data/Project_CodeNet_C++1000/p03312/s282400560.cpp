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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
ll s[MX], res = 1e18;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n) {
		cin >> a[i];
		s[i] = a[i];
		if (i) s[i] += s[i - 1];
	}

	forn (i, n - 1) {
		int p1 = lower_bound(s, s + n, s[i] / 2) - s;
		int p2 = lower_bound(s, s + n, s[i] + (s[n - 1] - s[i]) / 2) - s;

		for (int x = p1 - 4; x < p1 + 4; x++)
			for (int y = p2 - 4; y < p2 + 4; y++)
				if (0 <= x && x < i && i < y && y < n - 1) {
					vector<ll> v = {
						s[x],
						s[i] - s[x],
						s[y] - s[i],
						s[n - 1] - s[y]
					};
					sort(all(v));
					res = min(res, v[3] - v[0]);
				}
	}

	cout << res << endl;

	return 0;
}
