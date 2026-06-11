#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char p[5] = "LRDU";
struct point {
	long long x, y;
}w[1010], cur;
long long ab(long long a) { return a < 0 ? -a : a; }
long long Dist(point a, point b) {
	return ab(a.x - b.x) + ab(a.y - b.y);
}
long long d[40];
int main() {
	int i, j, ck = 0, k;
	d[0] = d[1] = 1;
	for (i = 0; i < 38; i++) {
		d[i + 2] = d[i] * 3;
	}
	scanf("%d", &n);
	int chk[2] = { 0,0 };
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
		chk[((w[i].x + w[i].y) % 2 + 2) % 2] = 1;
	}
	if (chk[0] && chk[1]) {
		puts("-1");
		return 0;
	}
	if (chk[1])ck = 1;
	m = 40 - ck;
	printf("%d\n", m);
	for (i = m - 1; i >= 0; i--)printf("%lld ", d[i]);
	puts("");
	for (i = 1; i <= n; i++) {
		cur.x = 0, cur.y = 0;
		for (j = m - 1; j >= 0; j--) {
			long long Mn = 1e18;
			int pv = -1;
			for (k = 0; k < 4; k++) {
				point tp = { cur.x + dx[k] * d[j], cur.y + dy[k] * d[j] };
				long long dd = Dist(tp, w[i]);
				if (Mn > dd)Mn = dd, pv = k;
			}
			printf("%c", p[pv]);
			cur.x += dx[pv] * d[j];
			cur.y += dy[pv] * d[j];
		}
		if (Dist(cur, w[i])) {
			puts("!!!");
		}
		puts("");
	}
}