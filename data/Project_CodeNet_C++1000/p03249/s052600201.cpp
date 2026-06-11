#include <iostream>
#include <algorithm>

using i64 = long long;

const int N = 100000 + 7;

int n;
int s[N], e[N];
i64 d[N], t;
int u[N], v[N];

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", d + i), e[i] = i, s[i] = 1;
	std::sort(e + 1, e + n + 1, [](int a, int b) {
		return d[a] < d[b];
	});
	for (int i = n; i > 1; --i) {
		int j = std::lower_bound(e + 1, e + n + 1, d[e[i]] - n + s[e[i]] * 2, [](int a, i64 b) {
			return d[a] < b;
		}) - e;
		if (d[e[j]] != d[e[i]] - n + s[e[i]] * 2) return printf("-1"), 0;
		s[e[j]] += s[e[i]], t += s[e[i]];
		u[i] = e[i], v[i] = e[j];
	}
	if (d[e[1]] != t) return printf("-1"), 0;
	for(int i = 2; i <= n; i++)
		printf("%d %d\n", u[i], v[i]);
	return 0;
}