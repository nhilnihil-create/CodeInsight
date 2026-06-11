#include <cstdio>
#include <algorithm>
#define fail return puts("-1"), 0

const int N = 1e3 + 5;

int n, sz;
long long x[N], y[N], bin[33];

void solve(long long x, long long y) {
	for (int i = sz - 1; i >= 0; i--) {
		if (std::labs(x) > std::labs(y)) {
			putchar(x < 0 ? 'L' : 'R');
			x < 0 ? x += bin[i] : x -= bin[i];
		} else {
			putchar(y < 0 ? 'D' : 'U');
			y < 0 ? y += bin[i] : y -= bin[i];
		}
	}
	puts("");
}
int main() {
	scanf("%d", &n);
	bool flg1 = false, flg2 = false;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		((x[i] + y[i]) & 1 ? flg1 : flg2) = true;
	}
	if (flg1 && flg2) fail;
	if (flg1) {
		printf("%d\n", sz = 33);
		for (int i = sz - 1; i >= 0; i--) {
			printf("%lld%c", bin[i] = 1LL << i, " \n"[i == 0]);
		}
	} else {
		printf("%d\n", sz = 34);
		for (int i = sz - 1; i >= 1; i--) {
			printf("%lld ", bin[i] = 1LL << (i - 1));
		}
		printf("%lld\n", bin[0] = 1);
	}
	for (int i = 1; i <= n; i++) solve(x[i], y[i]);
	return 0;
}