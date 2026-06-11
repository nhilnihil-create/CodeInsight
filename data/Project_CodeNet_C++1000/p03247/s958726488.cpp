#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x[1005], y[1005];

int main() {
	scanf("%d", &n);
	bool flag;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", x + i, y + i);
		x[i] += y[i];
		if (i == 1) flag = !(x[i] % 2);
		else if (x[i] % 2 == flag) return puts("-1"), 0;
		y[i] = x[i] - 2 * y[i];
	}
	printf("%d\n", 31 + flag);
	for (int i = 0; i <= 30; ++i)
		printf("%d ", 1 << i);
	if (flag) printf("1");
	puts("");
	for (int i = 1; i <= n; ++i) {
		if (flag) ++x[i], ++y[i];
		x[i] += (1ll << 31) - 1 - flag, y[i] += (1ll << 31) - 1 - flag;
		for (int j = 0; j <= 30; ++j) {
			static char s[2][2] = {{'L', 'D'}, {'U', 'R'}};
			putchar(s[x[i] >> j + 1 & 1][y[i] >> j + 1 & 1]);
		}
		if (flag) putchar('R');
		puts("");
	}
}
