// In the Name of God

#include <bits/stdc++.h>

using namespace std;

#define	ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(v) v.begin(), v.end()
#define bpc(v) __builtin_popcountll(v)
#define itr iterator
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define ub upper_bound
#define lb lower_bound

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const int pw = 257;

map<pair<string, int>, int> m;
int n;
string s;
ll ans;

int main() {
	#ifdef Madi
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	#endif
	                                            	
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    cin >> s;

	rep(mask, 0, (1 << n) - 1) {
		string t = "";
		rep(i, 0, n - 1)
			if (mask & (1 << i))
				t += s[i];			
		per(i, n - 1, 0)
			if (!(mask & (1 << i)))
				t += s[i];
		++m[mp(t, bpc(mask))];
	}
	rep(mask, 0, (1 << n) - 1) {
		string t = "";
		per(i, n - 1, 0)
			if (mask & (1 << i))
				t += s[i + n];
		rep(i, 0, n - 1)
			if (!(mask & (1 << i)))
				t += s[i + n];
		ans += m[mp(t, bpc(mask))];
//		cerr << t << ' ' << mask << ' ' << m[mp(t, bpc(mask))] << "\n";
	}

	cout << ans;
	#ifdef Madi
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}