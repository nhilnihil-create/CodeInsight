#include <bits/stdc++.h>
using namespace std;

int h, w, n, l[200005];

int main() {
	scanf("%d%d%d", &h, &w, &n);
	fill(l + 1, l + 1 + h, w + 1);
	for (int i = 0, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		l[x] = min(l[x], y);
	}
	int r = 1;
	for (int i = 2; i <= h; ++i) {
		if (l[i] <= r) {
			printf("%d\n", i - 1);
			return 0;
		}
		r = min(r + 1, l[i] - 1);
	}
	printf("%d\n", h);
}
