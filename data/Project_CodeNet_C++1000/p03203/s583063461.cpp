#include<stdio.h>
int main() {
	int h, w, n;
	int i, j, k;
	int c = 0;
	int a[200000] = {};

	scanf("%d %d %d", &h, &w, &n);

	for (k = 0; k < n; k++) {
		scanf("%d %d", &i, &j);
		if (i < j)continue;
		if (a[i] == 0 || a[i] > j)a[i] = j;
	}

	for (i = 1; i <= h; i++) {
		if (a[i] == 0) continue;

		if (a[i] == i - c) {
			c++;
			continue;
		}

		if (a[i] < i - c) {
			break;
		}
	}

	printf("%ld\n", i - 1);
	return 0;
}