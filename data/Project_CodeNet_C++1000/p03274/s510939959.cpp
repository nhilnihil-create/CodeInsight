#include <stdio.h>
int n, k, t, s, ans;
int x[100000];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	ans = 2 * (x[n - 1] - x[0]);
	for (int i = 0; i <= n - k; i++) {
		if (x[i] >= 0) t = x[i + k - 1];
		if (x[i + k - 1] <= 0)t = -x[i];
		if (x[i] < 0 && 0 < x[i + k - 1]) {
			t = 2 * x[i + k - 1] - x[i];
			s = x[i + k - 1] - 2 * x[i];
			if (t > s)t = s;
		}
		if (t < ans)ans = t;
	}
	printf("%d\n", ans);
}