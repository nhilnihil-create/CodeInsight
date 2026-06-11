#include <iostream>

using i64 = long long;

template<typename T> T abs(T x) { return x < 0 ? -x : x; }

const int N = 10000 + 7;

int n, m;
i64 x[N], y[N];
i64 c[N];

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", x + i, y + i);
		if ((x[1] + y[1] - x[i] - y[i]) & 1) return printf("-1"), 0;
	}
	m = 36;
	for (int i = 36; i; --i)
		c[i] = 1ll << 36 - i;
	if ((x[1] + y[1]) % 2 == 0) c[++m] = 1;
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i)
		printf("%lld ", c[i]);
	printf("\n");
	for(int i = 1; i <= n; ++i) {
		i64 u = 0, v = 0;
		for (int j = 1; j <= m; ++j) {
			i64 dx = abs(u - x[i]), dy = abs(v - y[i]);
			if (dx > dy)
				x[i] > u ? (printf("R"), u += c[j]) : (printf("L"), u -= c[j]);
			else
				y[i] > v ? (printf("U"), v += c[j]) : (printf("D"), v -= c[j]);
		}
		printf("\n");
	}
	return 0;
}
