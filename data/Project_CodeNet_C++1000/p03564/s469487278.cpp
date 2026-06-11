#include <stdio.h>

int main() {
	int n, k, v = 1;
	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		if (v < k) {
			v *= 2;
		}
		else if (v > k) {
			v += k;
		}
		else if (v = k) {
				v *= 2;
		}
		
	}
	printf ("%d\n", v);
	return 0;		
}