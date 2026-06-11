#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000;
int n, a, b, p[maxn + 10];
int suf[maxn + 10][maxn + 10], sum[maxn + 10][maxn + 10];
ll f[maxn + 10][maxn + 10];
int cmp(int x, int y) {
	return !x ? y : !y ? x : p[x] < p[y] ? x : y;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = n; j >= 1; --j)
			suf[j][i] = cmp(suf[j + 1][i], p[j] >= i ? j : 0);
		for (int j = 1; j <= n; ++j)
			sum[j][i] = sum[j - 1][i] + (p[j] >= i);
	}
	for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) {
			f[i][j] = 1e18;
			int pos = suf[i][j];
			if (!pos) f[i][j] = 0;
			else {
				f[i][j] = min(f[i][j], f[i][p[pos] + 1] + b);
				f[i][j] = min(f[i][j], 1ll * (sum[pos - 1][j] - sum[i - 1][j]) * a + f[pos + 1][p[pos] + 1]);
			}
		}
	}
	printf("%lld", f[1][1]);
}
