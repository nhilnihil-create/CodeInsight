#include <stdio.h>
#include <algorithm>
int n, r, t, x, z;
int d[23];
int e[23];
int main() {
	scanf("%d", &n);
	if (n >= 24) {
		printf("0\n");
		return 0;
	}
	r = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", d + i);
		r *= 2;
	}
	r /= 2;
	for (int i = 0; i < r; i++) {
		t = i;
		for (int j = 0; j < n; j++) {
			if (t % 2) e[j] = d[j];
			else e[j] = 24 - d[j];
			t /= 2;
		}
		std::sort(e, e + n);
		x = e[0];
		if (x > 24 - e[n - 1])x = 24 - e[n - 1];
		for (int j = 1; j < n; j++) {
			if (x > e[j] - e[j - 1])x = e[j] - e[j - 1];
		}
		if (z < x)z = x;
	}
	printf("%d\n", z);
}