#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define N 1234
#define int long long
template<typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-') flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
inline int F(int x) {
	return x < 0 ? -x : x;
}
int n;
int X[N], Y[N];
int d[43], dtot;
inline void work(int x, int y) {
	int nx = 0, ny = 0;
	for (int i = 1; i <= dtot; ++i) {
		int t = d[i];
		if (F(x - nx) > F(y - ny)) {
			if (x < nx)	putchar('L'), nx -= t;
			else	putchar('R'), nx += t;
		} else {
			if (y < ny)	putchar('D'), ny -= t;
			else putchar('U'), ny += t;
		}
	}
	putchar('\n');
}
signed main() {
	read(n);
	int type = -1;
	for (int i = 1; i <= n; ++i) {
		read(X[i]), read(Y[i]);
		int t = (X[i] + Y[i]) % 2;
		if (t < 0)	t += 2;
		if (type == -1)	type = t;
		else if (type != t) { puts("-1"); exit(0); }
	}
	if (type)	puts("31");
	else	puts("32");
	for (int i = 30; ~i; --i)	printf("%d ", 1 << i);
	if (type == 0)	puts("1");
	else	puts("");
	int nw = 30;
	if (type == 0) {
		for (int i = 0; i <= 30; ++i)	d[++dtot] = 1 << nw, --nw;
		d[++dtot] = 1;
	} else {
		for (int i = 0; i <= 30; ++i)	d[++dtot] = 1 << nw, --nw;
	}
	for (int i = 1; i <= n; ++i)	work(X[i], Y[i]);
	return 0;
}
