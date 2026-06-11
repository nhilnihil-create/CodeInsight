# include <stdio.h>
# include <bits/stdc++.h>


#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

using namespace std;

inline bool isvowel (char c) {
	c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u') return 1;
    return 0;
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m;
ll x;
string s;
int a[N];
vector < int > g[N];
int u[N];
ll ans;

ll get (ll k) {
    int c = 0;
    ll res = 0;
    For (i, 0, k - 1) g[i].clear();
    FOr (i, n, 1) {
        if (g[c].size()) {
            res += (g[c].back() - a[i]) * (g[c].size() + 1) * (g[c].size() + 1);
        } else {
            res += a[i];
        }
        g[c].pb(a[i]);
        c ++;
        if (c >= k) c -= k;
    }
    For (i, 0, k - 1) res += g[i].back() * (g[i].size() + 1) * (g[i].size() + 1);
    return res + x * n + x * k;
}

int main () {
	cin >> n >> x;
	For (i, 1, n) {
	    cin >> a[i];
	    
	}
	ans = INF;
	ll l = 1, r = n;
	while (l + 10 < r) {
	    ll m1 = l, m2 = r;
	    m1 += (r - l) / 3;
	    m2 -= (r - l) / 3;
	    if (get(m1) > get(m2)) l = m1;
	    else r = m2;
	}
	For (i, l, r) {
	    ans = min(ans, get(i));
	}
	
	cout << ans << '\n';
	return Accepted;
}

// Coded By OB