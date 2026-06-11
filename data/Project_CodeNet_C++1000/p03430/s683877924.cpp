#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 305;

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

template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

char s[N];
int n, K;
int dp[N][N][N];

void init() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    read(K);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= K; ++k) {
            dp[i][i][k] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int l = 1, r; (r = l + i) <= n; ++l) {
            for (int k = 0; k <= K; ++k) {
                cmax(dp[l][r][k], dp[l + 1][r][k]);
                cmax(dp[l][r][k], dp[l][r - 1][k]);
                if (s[l] == s[r]) {
                    cmax(dp[l][r][k], dp[l + 1][r - 1][k] + 2);
                } else if (k > 0) {
                    cmax(dp[l][r][k], dp[l + 1][r - 1][k - 1] + 2);
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= K; ++k) {
        cmax(ans, dp[1][n][k]);
    }
    printf("%d", ans);
}

int main() {
	init();
	solve();
	return 0;
}
