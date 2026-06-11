#include <stdio.h>
#include <algorithm>
int  l, m, r, s;
long long x, y, n;
int a[100000];
int e[100000];
int b[300001];
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		e[i] = a[i];
	}
	std::sort(e, e + n);
	l = 0;
	r = n;
	while (r - l - 1) {
		m = (l + r) / 2;
		b[s = n]++;
		x = 0;
		y = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < e[m]) {
				x += b[s];
				s++;
			}
			else {
				s--;
				x -= b[s];
			}
			b[s]++;
			y += x;
		}
		for (int i = 0; i <= 3 * n; i++) b[i] = 0;
		if (4 * y > (n * (n + 1))) r = m;
		else l = m;
	}
	printf("%d\n", e[l]);
}