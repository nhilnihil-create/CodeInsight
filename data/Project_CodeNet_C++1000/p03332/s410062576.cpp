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
// #define int long long
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define per(i, a, b) for (ll i = (a); i >= (b); i--)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
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
typedef double db ;
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
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 998244353 ;
const double eps = 1e-7 ;
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }
template <class T> void chmin(T &a, T b) { if (a > b) a = b ; }
template <class T> void chmax(T &a, T b) { if (a < b) a = b ; }
template <class T> void add(T &a, T b) { a = (1ll * a + b) % mod ; }
template <class T> void sub(T &a, T b) { a = (a - b + mod) % mod ; }
template <class T> void mul(T &a, T b) { a = (ll) a * b % mod ; }
template <class T> void read(T &a)
{
	int f = 1 ; a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch -'0' ; ch = getchar() ; }
	a *= f ;
}

ll n, a, b, k, x, y, ans;

ll fac[maxn], inv[maxn];

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

ll power(ll a, ll b)
{
	ll ret = 1;
	for(;b ; b >>= 1, (a *= a) %= mod) if(b & 1) (ret *= a) %= mod;
	return ret;
}

void init()
{
	fac[0] = 1;
	rep(i, 1, maxn - 1) fac[i] = fac[i - 1] * i % mod;
	inv[maxn - 1] = power(fac[maxn - 1], mod - 2);
	per(i, maxn - 1, 1) inv[i - 1] = inv[i] * i % mod;
	return ;
}

ll C(ll n, ll m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	init();
	read(n), read(a), read(b), read(k);
	ll g = exgcd(a, b, x, y);
	if(k % g) return puts("0"), 0;
	x *= k / g, y *= k / g;
	x = (x % (b / g) + (b / g)) % (b / g);
	y = (k - a * x) / b;
	if(y > n)
	{
		y = n + ((y - n) % (a / g) - a / g) % (a / g);
		x = (k - b * y) / a;
	}
	// cout<<x<<' '<<y<<endl;
	while(x <= n && y >= 0)
	{
		// cout<<C(n, x)<<' '<<C(n, y)<<endl;
		(ans += C(n, x) * C(n, y) % mod) %= mod;
		// cout<<ans<<endl;
		x += b / g, y -= a / g;
	}
	printf("%lld\n", ans);
	return 0;
}