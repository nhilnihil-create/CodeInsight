#include <bits/stdc++.h>
using namespace std;

int n, a[(1 << 18) + 5], ans[(1 << 18) + 5];

int main() {
	scanf("%d", &n);
	n = 1 << n;

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int mask = 1; mask < n; mask++) {
		int x = a[0], y = 0;
		for(int msk = mask; msk > 0; msk = (msk - 1) & mask) {
			if(a[msk] > x) {
				y = x;
				x = a[msk];
			}

			else if(a[msk] > y)
				y = a[msk];
		}

		ans[mask] = x + y;
	}

	for(int i = 1; i < n; i++) {
		ans[i] = max(ans[i - 1], ans[i]);
		printf("%d\n", ans[i]);
	}

	return 0;
}