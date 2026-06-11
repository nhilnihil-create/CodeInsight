// By Hacheylight

#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <numeric>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;
//#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter cout << endl
#define siz(x) ((int)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef long double ld ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef pair <ll, int> pli ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int N = 100010 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int mod = 1000000007 ;
const double eps = 1e-7 ;
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }
template <class T> void print(T a) { cout << a << endl ; exit(0) ; }
template <class T> void chmin(T &a, T b) { if (a > b) a = b ; }
template <class T> void chmax(T &a, T b) { if (a < b) a = b ; }
void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod ; }
void sub(int &a, int b) { a = (a - b + mod) % mod ; }
void mul(int &a, int b) { a = (ll) a * b % mod ; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a ; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a ; }
int mulv(int a, int b) { return (ll) a * b % mod ; }
int read() {
    int f = 1, x = 0 ;
    char ch = getchar() ;
    while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
    while (isdigit(ch)) { x = x * 10 + ch -'0' ; ch = getchar() ; }
    return x * f ;
}
int pw(int a, int b) {
	int s = 1 ;
	for (; b; b >>= 1, a = (ll) a * a % mod)
    if (b & 1) s = (ll) s * a % mod ;
    return s ;
}



signed main() {
	int n ;
	cin >> n ;
	vector <pli> e ;
	map <ll, int> ret ;
	rep(i, 0, n - 1) {
		ll x ; cin >> x ;
		ret[x] = i ;
		e.pb({x, i}) ;
	}
	sort(e.rbegin(), e.rend()) ;
	ll x = e.back().fi ;
	vi sz(n, 1) ;
	vector <ll> dp(n, 0) ;
	vector <pii> ans ;
	for (auto c : e) {
		if (c.fi != x) {
			if (sz[c.se] * 2 >= n) print(-1) ;
			ll need = c.fi - (n - 2 * sz[c.se]) ;
			if (!ret.count(need)) print(-1) ;
			int par = ret[need] ;
			dp[par] += dp[c.se] + sz[c.se] ;
			sz[par] += sz[c.se] ;
			ans.pb({c.se + 1, par + 1}) ;
		}
 	}
 	if (dp[e.back().se] != x) print(-1) ;
 	for (auto c : ans) cout << c.fi << " " << c.se << endl ;


	return 0 ;
}

