#include <bits/stdc++.h>

using namespace std;

const int MX = 200001;

int x[MX];
__int128_t s[MX];

int main() {
	int n, X;
	ignore = scanf("%d %d", &n, &X);
	for (int i = 1; i <= n; i++) {
		ignore = scanf("%d", x + i);
		s[i] = s[i - 1] + x[i];
	}
	
	__int128_t ans = 1e18;
	for (int k = 1; k <= n; k++) {
		__int128_t cur = X * 1ll * (n + k) + 2 * (s[n] - s[n - k]);
		for (int f = n, coef = 3; f > 0; f -= k, coef += 2) {
			__int128_t sum = s[f] - s[max(f - k, 0)];
			cur += sum * coef;
		}
		ans = min(ans, cur);
	}
	
	printf("%lld\n", (long long)ans);
	
	return 0;
}
