#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXLOG = 30; 
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, a[MAXN], b[MAXN], c[MAXN];
int getcnt(int x, int y) {
	return lower_bound(c + 1, c + n + 1, y + 1) - lower_bound(c + 1, c + n + 1, x);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	int ans = 0;
	for (int p = 1; p <= MAXLOG; p++) {
		int tmp = 1 << p, tnp = 1 << (p - 1);
		for (int i = 1; i <= n; i++)
			c[i] = b[i] % tmp;
		sort(c + 1, c + n + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int now = a[i] % tnp;
			if (a[i] & tnp) cnt += n - getcnt(tnp - now, tmp - 1 - now);
			else cnt += getcnt(tnp - now, tmp - 1 - now);
		}
		ans += (cnt & 1) * tnp;
	}
	writeln(ans);
	return 0;
}