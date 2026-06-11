#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, X[MAXN], Y[MAXN], ans[40], tot;

void out(int x, int y) {
	for (int i = 1; i <= tot; ++i) {
		if (abs(x) > abs(y)) {
			if (x < 0) {
				putchar('L');
				x += ans[i];
			} else {
				putchar('R');
				x -= ans[i];
			}
		} else {
			if (y < 0) {
				putchar('D');
				y += ans[i];
			} else {
				putchar('U');
				y -= ans[i];
			}
		}
	}
	puts("");
}

void init() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(X[i]); read(Y[i]);
		if (((X[i] + Y[i]) & 1) != ((X[1] + Y[1]) & 1)) {
			puts("-1"); exit(0);
		}
	}
}

void solve() {
	for (int i = 30; i >= 0; --i) {
		ans[++tot] = (1 << i);
	}
	if ((X[1] + Y[1]) % 2 == 0) {
		ans[++tot] = 1;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		out(X[i], Y[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}
