#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

typedef long long LL;

int main() {

	int Case;
	scanf("%d", &Case);
	while (Case--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		if (a == b) {
			printf("%d\n", 2 * (a - 1));
			continue;
		}

		int L = a - 1, R = b;
		while (L < R) {
			int mid = (L + R + 1) >> 1;
			if (1ll * mid * mid < 1ll * a * b) L = mid;
			else R = mid - 1;
		}
		LL lim = (1ll * a * b - 1) / L;
		printf("%d\n", L == lim ? 2 * L - 2 : 2 * L - 1);

	}

	return 0;
}