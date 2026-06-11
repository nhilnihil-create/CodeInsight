#include <cstdio>
const int N = 200005;
using LL = __int128; 
LL s[N], ans; int a[N], n, x;
LL E(int a, LL x) { return a == 1 ? x * 5 : (a * 2 + 1) * x; }
void put(LL val) { if (val > 9) put(val / 10); putchar(val % 10 + 48); }
int main() {
	std::scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) std::scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		LL sum = static_cast<LL> (i) * x;
		for (int j = i; j <= n; j += i) sum += E(j / i, s[n - j + i] - s[n - j]);
		sum += E(n / i + 1, s[n % i]);
		if (i == 1 || ans > sum) ans = sum;
	}
	put(ans + static_cast<LL> (n) * x);
	return 0;
}