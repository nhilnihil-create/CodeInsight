#include <bits/stdc++.h>

typedef long long ll;
const int N = 5054;

int n, L, R;
int p[N];
ll f[N][N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i, j;
	scanf("%d%d%d", &n, &R, &L);
	for (i = 1; i <= n; ++i) scanf("%d", p + i);
	for (i = 1; i <= n + 1; ++i) {
		for (j = 0; j < i; ++j) f[i][j] = f[i - 1][j] + (p[i] < p[j] ? L : R);
		f[i][i] = LLONG_MAX;
		for (j = 0; j < i; ++j) if (p[i] > p[j]) down(f[i][i], f[i - 1][j]);
	}
	printf("%lld\n", *std::min_element(f[n], f[n] + (n + 1)));;
	return 0;
}