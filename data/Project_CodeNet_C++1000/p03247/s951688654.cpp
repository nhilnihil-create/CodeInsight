#include <bits/stdc++.h>
#define int long long
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
typedef long long ll;
const int N = 10005;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

inline void chkmin(int &x, int y) { x = x < y ? x : y; }
template <class T> T sqr(T x) { return x * x; }

int n;
int x[N], y[N];
int d[1000];
bool flag;

int dis(int xa, int ya, int xb, int yb) {
	return abs(xa - xb) + abs(ya - yb);
}

signed main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
//	freopen("log", "w", stderr);
#endif
	ios::sync_with_stdio(false);

	cin >> n; 
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	flag = abs(x[1] + y[1]) & 1;

	for (int i = 1; i <= n; ++i)
		if ((abs(x[i] + y[i]) & 1) != flag)
			return puts("-1"), 0;

	puts(flag ? "31" : "32");
	for (int i = 1; i <= 31; ++i)
		printf("%lld ", d[i] = 1 << (31 - i));
	if (!flag) printf("%lld\n", d[32] = 1);
	else putchar('\n');

	for (int i = 1; i <= n; ++i) {
		int xd = 0, yd = 0;
		if (!flag) xd = 1;
		for (int j = 1; j <= 31; ++j) {
			char ch; int Dis = LLONG_MAX;
			if (dis(xd + d[j], yd, x[i], y[i]) < Dis)
				Dis = dis(xd + d[j], yd, x[i], y[i]), ch = 'R';
			if (dis(xd - d[j], yd, x[i], y[i]) < Dis)
			   	Dis = dis(xd - d[j], yd, x[i], y[i]), ch = 'L';
			if (dis(xd, yd + d[j], x[i], y[i]) < Dis)
				Dis = dis(xd, yd + d[j], x[i], y[i]), ch = 'U';
			if (dis(xd, yd - d[j], x[i], y[i]) < Dis)
				Dis = dis(xd, yd - d[j], x[i], y[i]), ch = 'D';
			if (ch == 'R') xd += d[j];
			if (ch == 'L') xd -= d[j];
			if (ch == 'U') yd += d[j];
			if (ch == 'D') yd -= d[j];
			putchar(ch);
		}
		if (xd != x[i] || yd != y[i]) return 1;
		if (!flag) putchar('R');
		putchar('\n');
	}

	return 0;
}