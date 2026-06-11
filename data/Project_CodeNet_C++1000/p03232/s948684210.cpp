#include <bits/stdc++.h>
#define MAX_N 100000
#define P 1000000007
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n; lnt ans;
lnt inv[MAX_N+5] = {1, 1};
lnt a[MAX_N+5], b[MAX_N+5];
int main() {
	read(n); for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 2; i <= n; i++) inv[i] = P-P/i*inv[P%i]%P;
	for (int i = 1; i <= n; i++) b[i] = (b[i-1]+inv[i])%P;
	for (int i = 1; i <= n; i++)
		(ans += (b[i]+b[n-i+1]-1+P)%P*a[i]%P) %= P;
	for (int i = 1; i <= n; i++) (ans *= i) %= P;
	return printf("%lld\n", ans), 0;
}