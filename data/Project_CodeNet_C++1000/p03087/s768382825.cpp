#include <stdio.h>
#include <algorithm>
int n, q, l, r;
char s[100001];
int a[100001];
int main() {
	scanf("%d%d", &n, &q);
	scanf(" %s", s);
	for (int i = 1; i < n; i++) {
		if (s[i] == 'C' && s[i - 1] == 'A')a[i + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", a[r] - a[l]);
	}
}