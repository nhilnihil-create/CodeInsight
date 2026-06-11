#include<cstdio>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int a[maxn], sum[maxn], n, nsum, tot, ans;
int step[maxn], inv[maxn], side_sum;
void Add(int &x, const int &a) {
	x += a;
	if(x >= mod) x -= mod;
}
int mul(const int &a, const int &b) {
	return 1ll * a * b % mod;
}
int dec(const int &a, const int &b) {
	return a - b < 0 ? a - b + mod : a - b;
}
int fpow(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = mul(ans, a);
		b >>= 1, a = mul(a, a);
	}
	return ans;
}
void pre(int n) {
	step[0] = inv[0] = 1;
	for(register int i = 1; i <= n; ++i)
		step[i] = mul(step[i - 1], i);
	inv[n] = fpow(step[n], mod - 2);
	for(register int i = n - 1; i >= 1; --i)
		inv[i] = mul(inv[i + 1], (i + 1));
}
int C(int n, int m) {
	return mul(mul(step[n], inv[n - m]), inv[m]);
}
int main() {
	scanf("%d", &n), pre(n + 3);
	for(register int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum[i] = sum[i - 1], Add(sum[i], a[i]);
	for(register int i = 1; i < n; ++i) {
		Add(nsum, dec(sum[n - i], sum[i]));
		Add(side_sum, a[n - i + 1]);
		Add(side_sum, a[i]);
		Add(ans, mul(mul(side_sum, step[i]), mul(C(n, i + 1), step[n - i - 1])));
		Add(ans, mul(mul(nsum, mul(2, step[i])), mul(C(n, i + 2), step[n - i - 2])));
	}
	Add(ans, mul(sum[n], step[n]));
	printf("%d", ans);
	return 0;
} 