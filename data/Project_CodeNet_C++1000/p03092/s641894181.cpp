#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1ll << 60;

int n, A, B, p[5005], q[5005], cnt[5005][5005];
ll f[5005];

int main() {
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 1; i <= n; ++i)
		scanf("%d", p + i), q[p[i]] = i;
	cnt[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		copy(cnt[i - 1], cnt[i - 1] + 1 + n, cnt[i]);
		++cnt[i][q[i]];
	}
	for (int i = 0; i <= n; ++i)
		partial_sum(cnt[i], cnt[i] + 1 + n, cnt[i]);
	p[n + 1] = n + 1;
	for (int i = 1; i <= n + 1; ++i) {
		f[i] = inf;
		for (int j = 0; j < i; ++j)
			if (p[j] < p[i])
				f[i] = min(f[i], f[j] + 1ll * (j == 0 ? 0 : cnt[p[i] - 1][j - 1] - cnt[p[j]][j - 1]) * A + 1ll * ((cnt[p[i] - 1][n] - cnt[p[i] - 1][j]) - (cnt[p[j]][n] - cnt[p[j]][j])) * B);
	}
	printf("%lld\n", f[n + 1]);
	return 0;
}
