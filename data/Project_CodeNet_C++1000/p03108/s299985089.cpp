#include <stdio.h>
int n, m, p, an, bn;
long long ans, g, ag, bg;
int x[100000];
int y[100000];
int a[100000];
int b[100000];
long long eans[100000];
int root(int c) {
	int t = 0;
	while (x[c] >= 0) {
		y[t] = c;
		c = x[c];
		t++;
	}
	for (int i = 0; i < t - 1; i++) {
		x[y[i]] = c;
	}
	return c;
}
void merge(int c, int d) {
	if (c == d)return;
	if (x[c] < x[d]) {
		x[c] += x[d];
		x[d] = c;
	}
	else if (x[c] == x[d]) {
		x[c] += x[d];
		x[d] = c;
	}
	else{
		x[d] += x[c];
		x[c] = d;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", a + i, b + i);
		a[i]--, b[i]--;
	}
	g = n;
	ans = g * (g - 1) / 2;
	for (int i = 0; i < n; i++)x[i] = -1;
	for (int i = m - 1; i >= 0; i--) {
		eans[i] = ans;
		an = root(a[i]);
		bn = root(b[i]);
		if (an != bn) {
			ag = x[an];
			bg = x[bn];
			ans -= ag * bg;
			merge(an, bn);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%lld\n", eans[i]);
	}
}