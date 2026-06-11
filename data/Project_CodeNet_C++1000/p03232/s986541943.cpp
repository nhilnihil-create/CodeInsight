#include<bits/stdc++.h>
#define mod int(1e9+7)
using namespace std;
int f[100010] = { 1 }, b[100010], a[100010], n;
int main() {
	scanf("%d", &n);
	b[n + 1] = 1;
	for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * 1LL * i) % mod;
	for (int i = n; i >= 1; i--) b[i] = (b[i + 1] * 1LL * i) % mod;
	for (int i = 1; i <= n; i++) a[i] = (a[i - 1] + 1LL * f[i - 1] * b[i + 1]) % mod;
	int res = 0;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		res = (res + ((long long)a[i] + a[n - i + 1])*x) % mod;
		res = (res + 1LL * (mod - f[n])*x) % mod;
	}
	printf("%d", res);
	return 0;
}