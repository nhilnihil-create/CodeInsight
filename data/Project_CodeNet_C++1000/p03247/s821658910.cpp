#include <cstdio>
#include <algorithm>
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;
const int P = 1000000007;
const double eps = 1e-6;
using namespace std;
inline int getint() {
    int r = 0; bool b = true; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') b = false; c = getchar(); }
    while (c >= '0' && c <= '9') { r = (r<<1)+(r<<3) + c - '0'; c = getchar(); }
    return b ? r : -r;
}
int n;
int x[MAXN], y[MAXN];
int cnt, mx[MAXN];
char dst[MAXN];
int main() {
    n = getint();
	for (int i = 0; i < n; ++i) {
		x[i] = getint();
		y[i] = getint();
	}
	int b = (abs(x[0] + y[0]) & 1);
	for (int i = 1; i < n; ++i)
		if ((abs(x[i] + y[i]) & 1) != b) {
			puts("-1");
			return 0;
		}
	printf("%d\n", 32 - b);
	dst[0] = 1;
	if (b == 0) printf("1 ");
	mx[0] = 0;
	for (int i = 1; i < 31; ++i)
		mx[i] = mx[i-1] * 2 + 1;
	for (int i = 0; i < 31; ++i)
		printf("%d ", (1<<i));
	putchar('\n');
	for (int i = 0; i < n; ++i) {
		int X = x[i], Y = y[i];
		if (b == 0) {
			putchar('R');
			--X;
		}
		cnt = 0;
		for (int j = 30; j >= 0; --j) {
			if ((LL) abs(X + (1<<j)) + abs(Y) <= (LL) mx[j]) {
				dst[++cnt] = 'L';
				X += (1<<j);
				continue;
			}
			if ((LL) abs(X - (1<<j)) + abs(Y) <= (LL) mx[j]) {
				dst[++cnt] = 'R';
				X -= (1<<j);
				continue;
			}
			if ((LL) abs(X) + abs(Y + (1<<j)) <= (LL) mx[j]) {
				dst[++cnt] = 'D';
				Y += (1<<j);
				continue;
			}
			if ((LL) abs(X) + abs(Y - (1<<j)) <= (LL) mx[j]) {
				dst[++cnt] = 'U';
				Y -= (1<<j);
				continue;
			}
		}
		for (int j = cnt; j >= 1; --j) putchar(dst[j]);
		putchar('\n');
	}
}
