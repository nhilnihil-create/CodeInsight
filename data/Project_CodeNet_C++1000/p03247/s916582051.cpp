#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int read() {
	int x = 0, f = 1; char ch;
	while(! isdigit(ch = getchar())) (ch == '-') && (f = -f);
	for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));
	return x * f;
}
template <class T> T Abs(T a) { return a > 0 ? a : -a; }
template <class T> T Max(T a, T b) { return a > b ? a : b; }
template <class T> T Min(T a, T b) { return a < b ? a : b; }
char s[N];
int n, m, x[N], y[N], len[N];
signed main() {
	n = read();
	for(int i = 1; i <= n; ++ i) x[i] = read(), y[i] = read();
	int tmp = Abs(x[1] + y[1]) & 1;
	for(int i = 2; i <= n; ++ i) if((Abs(x[i] + y[i]) & 1) != tmp) return puts("-1"), 0;
	len[1] = 1; m = 1; printf("%d\n1", 32 - tmp);
	if(tmp) for(int i = 1; i <= 30; ++ i) printf(" %d", len[++ m] = (1 << i));
	else for(int i = 0; i <= 30; ++ i) printf(" %d", len[++ m] = (1 << i));
	puts("");
	for(int i = 1, nx, ny; i <= n; ++ i) {
		nx = 0; ny = 0;
		for(int j = m, dx, dy; j; -- j) {
			dx = x[i] - nx; dy = y[i] - ny;
			if(Abs(dx) > Abs(dy)) {
				if(dx > 0) nx += len[j], s[j] = 'R';
				else nx -= len[j], s[j] = 'L';
			}
			else {
				if(dy > 0) ny += len[j], s[j] = 'U';
				else ny -= len[j], s[j] = 'D';
			}
		}
		printf("%s\n", s + 1);
	}
	return 0;
}
