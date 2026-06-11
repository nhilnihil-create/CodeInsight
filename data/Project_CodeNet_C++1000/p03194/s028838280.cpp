#include <cstdio>
#include <cmath>
#define LL long long

int main() {
	LL n, p;
	scanf("%lld%lld", &n, &p);
	LL ans = 1;
	LL cnt = 0;
	if (n == 1) {
		printf("%lld", p); return 0;
	}
	
	for (LL i = 2; i * i <= p; i++) {
		if (p % i == 0) {
			int cnt = 0;
			while (p % i == 0) {
				cnt++;
				p /= i;
				if (cnt % n == 0) ans *= i;
			}
		}
		if (p == 1) break;
	}
	printf("%lld", ans);
	return 0;
}