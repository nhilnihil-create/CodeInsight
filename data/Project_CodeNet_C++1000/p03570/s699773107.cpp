#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MAXS = (1 << 26) + 5;

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

char s[MAXN];
int n, dp[MAXS];

void solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	mset(dp, 0x3f);
	int S = dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		S ^= (1 << (s[i] - 'a'));
		dp[S] = dp[S] + 1;
		for (int j = 0; j < 26; ++j) {
			dp[S] = min(dp[S], dp[S ^ (1 << j)] + 1);
		}
		if (i < n) dp[0] = 0;
	}
	printf("%d\n", dp[S]);
}

int main() {
	solve();
	return 0;
}

