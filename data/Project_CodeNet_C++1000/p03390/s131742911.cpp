#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int main() {
	int T; read(T);
	while (T--) {
		int x, y; read(x), read(y);
		if (x == y) {
			printf("%d\n", x + y - 2);
			continue;
		}
		if (x > y) swap(x, y);
		int ans = x - 1;
		int l = 0, r = y;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (1ll * mid * mid < 1ll * x * y) l = mid;
			else r = mid - 1;
		}
		ans += (1ll * x * y - 1) / (l + 1) - x;
		ans += l;
		writeln(ans);
	}
	return 0;
}