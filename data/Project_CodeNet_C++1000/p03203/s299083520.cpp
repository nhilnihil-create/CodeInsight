#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
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

const int N = 5e5 + 233;
int H, W, n;
set <int> pos[N];

int main(void) {
	read(H); read(W); read(n);
	rep (i, n) {
		int x, y; read(x); read(y);
		pos[y].insert(x);
	}
	rep (i, W) pos[i].insert(H + 1);
	int ans = 1e9, y = 1;
	for (int x = 1; x <= H; x++) {
		// cout << x << " " << y << " " << *pos[y].lower_bound(x) - 1 << "\n";
		ans = min(ans, *pos[y].lower_bound(x) - 1);
		if (y < W && !pos[y + 1].count(x + 1)) ++y;
	}
	cout << ans << "\n";
}
