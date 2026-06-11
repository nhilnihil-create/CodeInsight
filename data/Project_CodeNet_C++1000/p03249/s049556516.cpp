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
	scanf("%d", &n) ;
	vector <ll> d(n) ;
	vi sz(n, 1) ;
	map <ll, int> hsh ;
	rep(i, 0, n - 1) {
		scanf("%lld", &d[i]) ;
		hsh[d[i]] = i ;
	}
	vector <pii> res ;
	rep(itt, 0, n - 2) {
		auto it = hsh.rbegin() ;
		int i = it->se ;
		ll want = d[i] + 2 * sz[i] - n ;
		if (hsh.find(want) == hsh.end() || hsh[want] == i) print(-1) ;
		int j = hsh[want] ;
		res.emplace_back(j, i) ;
		sz[j] += sz[i] ;
		hsh.erase(--hsh.end()) ;
	}
	vector <ll> real(n, -1) ;
	real[0] = 0 ;
	vector <vi> g(n) ;
	for (auto &p : res) {
		g[p.fi].pb(p.se) ;
		g[p.se].pb(p.fi) ;
	}
	vi que(1, 0) ;
	rep(b, 0, siz(que) - 1) {
		for (int j : g[que[b]]) {
			if (real[j] == -1) {
				que.pb(j) ;
				real[j] = real[que[b]] + 1 ;
			}
		}
	}
	if (accumulate(real.begin(), real.end(), 0LL) != d[0]) print(-1) ;
	sort(res.begin(), res.end()) ;
	for (auto &p : res) printf("%d %d\n", p.fi + 1, p.se + 1) ;
	return 0 ;
}

