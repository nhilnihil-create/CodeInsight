#include <stdio.h>
int n, m, p, an, bn, f, ans;
int a[50];
int b[50];
int x[50];
int y[50];
int z[50];
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
		x[d] = c;
	}
	else if (x[c] == x[d]) {
		x[d] = c;
		x[c]--;
	}
	else{
		x[c] = d;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", a + i, b + i);
		a[i]--, b[i]--;
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++)x[i] = -1;
		for (int i = 0; i < m; i++) {
			if (i != j) {
				an = root(a[i]);
				bn = root(b[i]);
				merge(an, bn);
			}
		}
		f = 0;
		for (int i = 1; i < n; i++) {
			if (root(0) != root(i))f = 1;
		}
		if (f)ans++;
	}
	printf("%d\n", ans);
}