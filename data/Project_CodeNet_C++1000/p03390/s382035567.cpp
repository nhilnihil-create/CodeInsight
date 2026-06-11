#include <bits/stdc++.h>

using namespace std;

int q;
long long x, y;
map<long long, int> m;
int main( ) {
	scanf("%d", &q);
	while (q --) {
		scanf("%lld %lld", &x, &y);
		if (x > y) swap(x, y);
		long long tmp = 1LL * x * y - 1;

		int l = 1, r = (int )1e9;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1LL * mid * mid < tmp) l = mid + 1;
			else r = mid - 1;
		}
		printf("%lld\n", min(x - 1, tmp / (y + 1)) + min(1LL * r, tmp / (x + 1)) + max((tmp / (r + 1)) - x, 0LL));
		//printf("fuck %lld %lld\n", min(tmp / (y + 1), x - 1), min(tmp / (x + 1), y - 1));
	}
	return 0;
}
