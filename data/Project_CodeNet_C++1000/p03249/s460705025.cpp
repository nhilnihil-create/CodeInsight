#include <bits/stdc++.h>
//#define inf 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inv(x) Power(x, mod - 2)
#define fi first
#define se second
#define MP make_pair
#define PB push_back

typedef std::vector<int> Poly;
typedef std::pair<int,int> Pair;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;

const int maxn = 100000, maxm = 2000, MAX = 1e6 + 5, mod = 1000000;
//template{{{
const long double Pi = 3.14159265358979323846l, Eps = 1e-4;
template <class T> inline bool equal(T x, T y) { return fabs(x - y) < Eps; }
inline int add(int x, int y) { x += y; return x >= mod ? x - mod : x; };
inline void inc(int &x, int y) { x += y; x -= (x >= mod ? mod : 0); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int Power(int x, int y, int Mod = mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = (ll) ans * x % Mod;
		x = (ll) x * x % Mod, y >>= 1;
	} return ans;
}

/*char buf[1<<23],obuf[1<<23],*p1=buf,*p2=buf, *O = obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void print(int x) {
    if(x > 9) print(x / 10);
    *O++=x%10+'0';
} */

template <class T> inline T	input() {
	T x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return flag ? -x : x;
}

template <class T> inline bool chkmin(T &x, T y) { x = x < y ? x : y; return x == y; }
template <class T> inline bool chkmax(T &x, T y) { x = x > y ? x : y; return x == y; }
template <class T> inline T gcd(T x, T y) { return !y ? x : gcd(y, x % y); }
template <class T> inline T sqrm(T x) { return (ll) x * x % mod; }
template <class T> inline T sqr(T x) { return x * x; }

struct {
	inline operator int () { return input<int>(); }
	inline operator long long () { return input<long long>(); }
	template <class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read; //}}}

int n;
ll d[maxn + 5];
int size[maxn + 5];
std::map<ll, int> id;
std::pair<ll, int> p[maxn + 5];
std::vector<int> T[maxn + 5];
int fa[maxn + 5];

ll distance;

void dfs(int u, ll dis) {
	distance += dis;
	for (int v : T[u])
		dfs(v, dis + 1);
}

bool check() {
	dfs(p[1].se, 0);
	return distance == d[p[1].se];
}

signed main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "w", stderr);
#endif

	n = read;
	for (int i = 1; i <= n; ++i) {
		p[i].fi = d[i] = read;
		p[i].se = id[d[i]] = i;
		size[i] = 1;
	}

	std::sort(p + 1, p + n + 1);
	for (int i = n; i > 1; --i) {
		ll df = p[i].fi - n + size[p[i].se] * 2;
		if (df >= p[i].fi) return puts("-1"), 0;
		fa[p[i].se] = id[df], size[fa[p[i].se]] += size[p[i].se];
		if (!fa[p[i].se]) return puts("-1"), 0;
		T[fa[p[i].se]].push_back(p[i].se);
	}

	if (!check()) return puts("-1"), 0;

	for (int i = 1; i <= n; ++i)
		if (fa[i]) printf("%d %d\n", i, fa[i]);
	return 0;
}
