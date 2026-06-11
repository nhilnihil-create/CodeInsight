#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 310;
const ll mod = 1e9 + 7;

int x[N * N], y[N * N];
vector<int> c[N * N];

int main()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1, p; j <= m; ++j) {
			scanf("%d", &p);
			x[p] = i, y[p] = j;
		}
	}
	for (int i = 0; i < d; ++i) {
		c[i].push_back(0);
		for (int j = i + d, k = 1; j <= n * m; j += d, ++k) {
			c[i].push_back(c[i][k - 1] + abs(x[j] - x[j - d]) + abs(y[j] - y[j - d]));
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r, z;
		scanf("%d %d", &l, &r);
		z = l % d;
		l = l / d, r = r / d;
		printf("%d\n", c[z][r] - c[z][l]);
	}
	return 0;
}