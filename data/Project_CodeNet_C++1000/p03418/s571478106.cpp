#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	long long ans = 0ll;
	for (int b = 1; b <= n; b++) {
		if (b <= k)
			continue;
		ans += (n / b) * (b - k);
		int tmp = n - (n / b) * b;
		if (tmp > 0 && tmp >= k)
			ans += min(tmp, tmp - k + 1);
	}
	printf("%lld", ans);
}