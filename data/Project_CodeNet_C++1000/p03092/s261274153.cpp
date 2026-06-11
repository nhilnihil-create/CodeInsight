#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 5005;

int A, B, N, pos[MN];
LL f[MN * 2], g[MN * 2];

int main() {
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 1, x; i <= N; ++i)
		scanf("%d", &x), pos[x] = i;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N * 2 + 1; ++j)
			g[j] = j & 1 ? j > 1 ? std::min({g[j - 2], f[j - 1], f[j]}) : f[1] : g[j - 1];
		for (int j = 1; j <= N * 2 + 1; ++j)
			g[j] += j > 2 * pos[i] ? A : j < 2 * pos[i] ? B : 0;
		std::swap(f, g);
	}
	printf("%lld\n", *std::min_element(f + 1, f + 2 * N + 2));
	return 0;
}