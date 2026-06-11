#include <stdio.h>

int main() {
	int n, k, x = 1;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		if (x < k) {
			x *= 2;
		} else {
			x += k;
		}
	}
	printf("%d\n", x);
	
	return 0;
}