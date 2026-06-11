#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
template <typename T>
inline void read(T &x) {
	x = 0;
	char ch = 0;
	bool sign = false;
	while (ch < '0' || '9' < ch) sign |= ch == '-', ch = getchar();
	while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x = sign ? -x : x;
}
template <typename T>
inline void print(T x) {
	static char outp[64];
	if (!x) { putchar('0'); return; }
	if (x < 0) putchar('-'), x = -x;
	int tot = 0;
	while (x) outp[tot++] = x % 10 + '0', x /= 10;
	while (tot) putchar(outp[--tot]);
}
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rt register int
#define all(it) it.begin(), it.end()
#define rep(it, f, e) for (rt it = f; it <= e; ++it)
#define per(it, f, e) for (rt it = f; it >= e; --it)
const int MAXN = 1e3 + 10;
const int MAXW = 1e4 + 10;
struct Node {
	int w, s, v;
}	ob[MAXN];
inline bool cmp(Node a, Node b) {
	return a.w + a.s < b.w + b.s;
}
ll dp[MAXN][MAXW << 1];
#define max(a, b) (a > b ? a : b)
int main() {
	int n, m = 0;
	read(n);
	rep (i, 1, n) {
		read(ob[i].w);
		read(ob[i].s);
		read(ob[i].v);
		m = max(m, ob[i].s);
	}
	m <<= 1;
	sort(ob + 1, ob + n + 1, cmp);
	ll ans = 0 ;
	rep (i, 1, n) {
		rep (j, 1, m) {
			dp[i][j] = dp[i - 1][j];
			if (ob[i].s >= j - ob[i].w && j >= ob[i].w) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - ob[i].w] + ob[i].v);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}