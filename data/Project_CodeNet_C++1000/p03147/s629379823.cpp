#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read() {
	LL x = 0, fh = 1;
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
const int N = 110;
int n, ans, i, j, a[N];
int main() {
	n = read();
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) {
		j = i;
		while (a[j] == a[j + 1]) j++;
		if (a[i] > a[i - 1] && a[j] > a[j + 1]) ans += a[i];
		if (a[i] < a[i - 1] && a[j] < a[j + 1]) ans -= a[i];
		i = j;
	}
	cout << ans << '\n';
	return 0;
}