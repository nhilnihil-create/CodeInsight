#include <bits/stdc++.h>
typedef long long LL;
const int maxn = 300010;
const int inf = 1 << 30;
const int mod = 1e9+7;

inline int read() {
	register int x = 0, neg = 1;
	register char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = (((x << 2) + x) << 1) + (ch ^ '0'); ch = getchar(); }
	return x * neg;
}

int n;
LL a[maxn], pre[maxn];
LL fac = 1, ans = 0;

inline LL qpow(LL a, LL n) {
	if(n == 0) return 1;
	LL res = 1;
	while(n) {
		if(n & 1) res = (res * a) % mod;
		n >>= 1;
		a = (a * a) % mod;
	} 
	return res;
}

inline LL inv(LL x) {
	return qpow(x, mod - 2);
}

int main() {
	n = read();
	for(register int i = 1; i <= n; ++i) a[i] = read();
	for(register int i = 1; i <= n; ++i) {
		pre[i] = (pre[i - 1] + inv(i)) % mod;
		fac = fac * i % mod;
	}
	for(register int i = 1; i <= n; ++i) {
		ans = (ans + a[i] * (pre[i] + pre[n - i + 1] - 1) % mod) % mod;
	}
	printf("%lld\n", fac * ans % mod);
	return 0;
}