#include<cstdio>
#include<cstring>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

#define REP(i,n) for(int i=0;i<(n);i++)

const int MAXN = 500 + 10;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int ans[MAXN][MAXN];

void init() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(ans, 0, sizeof(ans));
}
int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	init();
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		a[l][r]++;
	}

	for (int j = 1; j <= n; j++) {
		b[j][j] = a[j][j];
		for (int i = j - 1; i >= 1; i--) {
			b[i][j] = b[i + 1][j] + a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		ans[i][i] = a[i][i];
		for (int j = i + 1; j <= n; j++) {
			ans[i][j] = ans[i][j - 1] + b[i][j];
		}
	}
	while (q--) {
		int li, ri;
		scanf("%d %d", &li, &ri);
		printf("%d\n", ans[li][ri]);
	}
	return 0;
}
