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
#define int long long
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (ll i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
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
#define enter putchar('\n')
#define siz(x) ((ll)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <ll, ll> pii ;
typedef vector <ll> vi ;
typedef vector <pii> vii ;
typedef queue <ll> qi ;
typedef queue <pii> qii ;
typedef set <ll> si ;
typedef map <ll, ll> mii ;
typedef map <string, ll> msi ;
const ll maxn = 5e3 + 100 ;
const ll inf = 0x3f3f3f3f ;
const ll iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 998244353 ;
const double eps = 1e-7 ;
template <class T = ll> T chmin(T &a, T b) { return a = min(a, b);}
template <class T = ll> T chmax(T &a, T b) { return a = max(a, b);}
template <class T = ll> T read()
{
	T f = 1, a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }
	return a * f ;
}

ll n, vl, vr, ans = linf;

ll a[maxn];

ll f[maxn][maxn];

signed main()
{
	n = read(), vr = read(), vl = read();
	rep(i, 1, n) a[i] = read();
	ass(f, 0x3f);
	f[0][0] = 0;
	rep(i, 0, n - 1)
	{
		rep(j, 0, n)
		{
			chmin(f[i + 1][j], f[i][j] + (a[i + 1] > j ? vr : vl));
			if(a[i + 1] > j) chmin(f[i + 1][a[i + 1]], f[i][j]);
		}
	}
	rep(i, 0, n) chmin(ans, f[n][i]);
	printf("%lld\n", ans);
	return 0;
}