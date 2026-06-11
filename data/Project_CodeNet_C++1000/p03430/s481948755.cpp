%:pragma GCC optimize("Ofast", "inline")
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

namespace {
    const int mo = 1e9 + 7;
    inline int add(int x, int y) { x += y; return x >= mo ? x - mo : x; }
    inline int sub(int x, int y) { x -= y; return x < 0 ? x + mo : x; }
    inline int mul(int x, int y) { return (lo) x * y % mo; }
    inline int power(int a, int k = mo - 2) {
		int ans = 1;
		for (; k; k >>= 1, a = mul(a, a))
			if (k & 1) ans = mul(ans, a);
		return ans;
    }
	inline void U(int &x, int y) { x = add(x, y); } 
}

const int N = 333;
int n, K;
int dp[N][N][N];
char str[N];

inline int dfs(int l, int r, int k) {
	if (k < 0) return -1e9;
	if (l > r) return 0;
	if (l == r) return 1;
	if (~dp[l][r][k]) return dp[l][r][k];
	int &ans = dp[l][r][k] = 0;
	ans = max(ans, max(dfs(l + 1, r, k), dfs(l, r - 1, k)));
	ans = max(ans, 2 + dfs(l + 1, r - 1, k - 1));
	ans = max(ans, (str[l] == str[r]) * 2 + dfs(l + 1, r - 1, k));
	// cout << l << " " << r << " " << k << " "<< ans << "\n";
	return ans;
}

int main(void) {
	memset(dp, -1, sizeof dp);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	read(K);
	// cout << dfs(1, n, K) << "\n";
	// return 0;
	int ans = 0;
	rep (r, n) rep (l, r) ans = max(ans, dfs(l, r, K));
	cout << ans << "\n";
}
