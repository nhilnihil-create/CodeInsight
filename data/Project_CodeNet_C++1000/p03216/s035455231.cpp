#include <stdio.h>
int n, q, k;
char s[1000001];
long long a, b, c, d;
int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	scanf("%d", &q);
	for (int j = 0; j < q; j++) {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		scanf("%d", &k);
		for (int i = 0; i < n; i++) {
			if (0 <= i - k) {
				if (s[i - k] == 'D') {
					a--;
					c -= b;
				}
				if (s[i - k] == 'M')b--;
			}
			if (s[i] == 'D')a++;
			if (s[i] == 'M') {
				b++;
				c += a;
			}
			if (s[i] == 'C')d += c;
		}
		printf("%lld\n", d);
	}
}