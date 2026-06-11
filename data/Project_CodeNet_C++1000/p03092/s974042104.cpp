#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 5005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

template <typename T> inline void cmin(T &x, T y) {
	if (x > y) x = y;
}

int n, A, B, p[N];
LL dp[2][N], ans;

void init() {
	read(n); read(A); read(B);
	for (int i = 1; i <= n; ++i) {
        read(p[i]);
	}
}

void solve() {
	mset(dp[0], 0x3f);
	ans = dp[0][0];
	dp[0][0] = 0;
	int cur = 0, pre = 1;
	for (int i = 1; i <= n; ++i) {
        swap(cur, pre);
        mset(dp[cur], 0x3f);
        for (int j = 0; j < i; ++j) {
            if (p[i] > p[j]) {
                cmin(dp[cur][i], dp[pre][j]);
                cmin(dp[cur][j], dp[pre][j] + A);
            } else {
                cmin(dp[cur][j], dp[pre][j] + B);
            }
        }
	}
	for (int i = 1; i <= n; ++i) {
        cmin(ans, dp[cur][i]);
	}
	printf("%lld\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
