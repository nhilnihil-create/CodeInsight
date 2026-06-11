#include<cstdio>
#include<algorithm>
long long floorsqrt(long long n) {
	if (n < 4)return (long long)1;
	long long a = n / 2, b = 2;
	while (std::abs(a - b) > 1) {
		b = (a + b) / 2;
		a = n / b;
	}
	return a < b ? a : b;
}
int main() {
	long long q, a, b, i, c, ans;
	scanf("%lld", &q);
	for (i = 0; i < q; i++) {
		scanf("%lld%lld", &a, &b);
		if (a < b) {
			c = a;
			a = b;
			b = c;
		}
		if (a == b || a==b+1)ans = 2 * b - 2;
		else {
			c = floorsqrt(a*b);
			if (c*c == a*b)c--;
			if (c*(c + 1) >= a*b)ans = 2 * c - 2;
			else ans = 2 * c - 1;
		}
		printf("%lld\n", ans);
	}
}