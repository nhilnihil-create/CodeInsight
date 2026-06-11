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
const int N = 3e5 + 233;
int sg[N];
int n, ans;
vector <int> G[N];

inline int dfs(int u, int fat) {
	int mx = 0, se = 0;
	for (int v : G[u])
		if (v != fat) {
			int t = dfs(v, u) + 1;
			if (t >= mx) se = mx, mx = t;
			else if (t >= se) se = t;
		}
	ans = max(ans, mx + se);
	return mx;
}

int main(void) {
	sg[0] = 0; sg[1] = 1; sg[2] = 0;
	for (int i = 3; i < N; i++) {
		set <int> cur;
		cur.insert(sg[i - 1]);
		cur.insert(sg[i - 2]);
		int t = 0;
		while (cur.count(t)) ++t;
		sg[i] = t;
	}
	read(n);
	rep (i, n - 1) {
		int x, y; read(x); read(y);
		G[x].push_back(y); G[y].push_back(x);
	}
	dfs(1, 0);
	++ans;
	cout << (sg[ans] ? "First" : "Second") << "\n";
}
