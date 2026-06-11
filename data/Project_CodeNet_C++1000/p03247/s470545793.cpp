#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

typedef long long LL;

const int MAXN = 1e5 + 10;
int n, sz, f;
LL b[50], x[MAXN], y[MAXN];

inline void print(LL x, LL y) {
	for (int i = 1; i <= sz; ++i) {
		if (labs(x) > labs(y)) {
			if (x > 0) putchar('R'), x -= b[i];
			else putchar('L'), x += b[i];
		} else {
			if (y > 0) putchar('U'), y -= b[i];
			else putchar('D'), y += b[i];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld%lld", x + i, y + i), f |= 1 << (x[i] + y[i] & 1);
	if (f == 3) return puts("-1"), 0;
	for (int i = 35; ~i; --i) b[++sz] = 1LL << i;
	if (f & 1) b[++sz] = 1;
	printf("%d\n", sz);
	for (int i = 1; i <= sz; ++i) printf("%lld%c", b[i], " \n"[i == sz]);
	for (int i = 1; i <= n; ++i) print(x[i], y[i]), puts("");
	return 0;
}