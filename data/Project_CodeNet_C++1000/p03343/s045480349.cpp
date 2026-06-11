#include <bits/stdc++.h>
#define MAX_N 2000
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, l, a[MAX_N+5], b[MAX_N+5], c[MAX_N+5], d[MAX_N+5];
bool cmp(const int &x, const int &y) {return a[x] < a[y];}
int main() {
	read(n), read(l), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]), b[i] = i;
	sort(b+1, b+n+1, cmp); int ans = 0x3f3f3f3f;
	for (int l = 1, r; l <= n; l++) {
		int cnt = 0, tim = 0;
		memset(c, 0, sizeof c), memset(d, 0, sizeof d);
		for (int p = 1, q; p <= n; p = max(p+1, q)) {
			for (q = p; a[q] >= a[b[l]]; q++) ; cnt++;
			for (int i = p; i < q; i++) d[c[i] = cnt]++;
		}
		for (r = l; tim < m && r <= n; r++)
			if (d[c[b[r]]] >= ::l) d[c[b[r]]]--, tim++;
		if (tim == m) ans = min(ans, a[b[r-1]]-a[b[l]]);
	}
	return printf("%d\n", ans), 0;
}
