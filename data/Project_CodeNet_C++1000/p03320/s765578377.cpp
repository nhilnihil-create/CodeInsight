#include <bits/stdc++.h>
#define int long long
using namespace std;

double solve(int x) {
	int res = 0, k = x;
	while (k) {
		res += k % 10;
		k /= 10;
	}
	return (x * 1.0) / (res * 1.0);
}

signed main() {
	int n, ans = 0, base = 1;
	scanf("%lld", &n);
	while (n--) {
		while (solve(ans + base) > solve(ans + base * 10)) {
			base *= 10;
		}
		ans += base;
		printf("%lld\n", ans);
	}
	return 0;
}