#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
const int N = 1e5 + 10;
int n, m, x, y, z, kx, ky, ans, i, f[N];
int find_root(int x) {
	if (x == f[x]) return x;
	return f[x] = find_root(f[x]);
}
int main() {
	n = read(); m = read();
	for (i = 1; i <= n; i++) f[i] = i;
	for (i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		kx = find_root(x);
		ky = find_root(y);
		if (kx != ky) f[kx] = ky;
	}
	for (i = 1; i <= n; i++) if (f[i] == i) ans++;
	cout << ans;
	return 0;
}