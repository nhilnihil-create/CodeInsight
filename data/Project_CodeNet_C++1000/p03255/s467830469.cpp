#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (int)(n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}

#define int __int128
const int N = 3e5 + 233;
int n, X;
int x[N], sp[N];
inline int getsum(int L, int R) {
	L = max <__int128> (L, 0);
	if (L > R) return 0;
	return sp[R] - (L ? sp[L - 1] : 0);
}

signed main(void) {
	read(n); read(X);
	rep (i, n) read(x[i]), sp[i] = sp[i - 1] + x[i];
	int ans = 1e18;
	rep (k, n) {
		int cur = X * k + getsum(n - k + 1, n) + n * X;
		for (int i = n, t = 2; i >= 1; i -= k, ++t) {
			int dist = getsum(i - k + 1, i) - getsum(i - 2 * k + 1, i - k);
			cur += dist * t * t;
		}
		// cout << k << " " << cur << "\n";
		ans = min(ans, cur);
	}
	cout << (unsigned long long) ans << "\n";
}
