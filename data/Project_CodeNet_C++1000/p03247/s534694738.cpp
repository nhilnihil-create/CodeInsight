#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1009;
int n, x[N], y[N], vis = -1, maxn, cnt;
ll a[45];
char ans[45], dir[4] = {'L', 'R', 'D', 'U'};
double dis[4];

void read(int &x) {
	char c; int f = 1;
	for (c = getchar(); c < '0' || c > '9'; c = getchar()) if (c == '-') f = 0;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x = f ? x : -x;
}

inline int Log(int x) {
	int t = (int)(log(x) / log(2));
	if ((1 << t) == x) return t;
	return t + 1;
}

inline double get_dis(ll x1, ll Y1, ll x2, ll y2) {return sqrt((x1 - x2) * (x1 - x2) + (Y1 - y2) * (Y1 - y2));}

int main() {
	read(n);
	for (int i = 1; i <= n; ++ i) {
		read(x[i]), read(y[i]);
		if (((x[i] + y[i]) % 2 && vis == 0) || ((x[i] + y[i]) % 2 == 0 && vis == 1)) return puts("-1"), 0;
		vis = (x[i] + y[i]) % 2;
		maxn = max(maxn, abs(x[i]) + abs(y[i]));
	}
	if (vis == 0) a[++ cnt] = 1;
	for (int i = 1; i <= Log(maxn); ++ i) a[++ cnt] = 1LL << i - 1;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; ++ i) printf("%lld ", a[i]); putchar('\n');
	for (int i = 1; i <= n; ++ i) {
		ll nx = 0, ny = 0;
		for (int j = cnt; j; -- j) {
			dis[0] = get_dis(nx - a[j], ny, x[i], y[i]);
			dis[1] = get_dis(nx + a[j], ny, x[i], y[i]);
			dis[2] = get_dis(nx, ny - a[j], x[i], y[i]);
			dis[3] = get_dis(nx, ny + a[j], x[i], y[i]);
			int minnum = 0;
			for (int k = 0; k < 4; ++ k) if (dis[minnum] > dis[k]) minnum = k;
			if (minnum == 0) nx -= a[j];
			if (minnum == 1) nx += a[j];
			if (minnum == 2) ny -= a[j];
			if (minnum == 3) ny += a[j];
			ans[j] = dir[minnum];
		}
		for (int j = 1; j <= cnt; ++ j) putchar(ans[j]); putchar('\n');
	}
	return 0;
}
