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
const int N = 1e6 + 10;
int n, k, i, j, v[N];
double fac, ans;
int main() {
	n = read(); k = read();
	for (i = 1; i <= n; i++) for (j = i; j < k; j <<= 1, v[i]++);
	for (i = 1; i <= n; i++) {
		fac = 1.0 / n;
		for (j = 1; j <= v[i]; j++) fac *= 0.5;
		ans += fac;
	}
	printf("%.12lf", ans);
	return 0;
}