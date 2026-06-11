#include <climits>
#include <cstdio>
#include <algorithm>

typedef long long LL;
const int N = 2e5 + 10;

LL x[N], s[N], X, ans = LLONG_MAX;
int n;

int main() {
	scanf("%d%lld", &n, &X);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x[i]);
		s[i] = s[i-1] + x[i];
	}
	for (int k = 1; k <= n; ++k) {
		LL cur = 0, E = 3;
		for (int i = n; i > 0; i -= k) {
			cur += (s[i] - s[std::max(i-k, 0)]) * std::max(E, 5LL);
			E += 2;
			if (cur >= ans) {
				break;
			}
		}
		cur += X * (k + n); // 捡垃圾和倒垃圾的花费 
		if (cur < ans) ans = cur;
	}
	printf("%lld", ans);
	return 0;
}