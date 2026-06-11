#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1, MAXN = 3e5 + 10, mod = 998244353;
int fc[N], ifc[N];
long long  power(long long a, long long b) {
	if (!b)
		return 1;
	long long rtr = power(a, b / 2);
	if (b % 2)
		return rtr * rtr % mod * a % mod;
	return rtr * rtr % mod;
}
void getFc() {
	fc[0] = ifc[0] = 1;
	for (int i = 1; i < N; i++) {
		fc[i] = 1ll * fc[i - 1] * i % mod;
		ifc[i] = 1ll * ifc[i - 1] * power(i, mod - 2) % mod;
	}
	return;
}
long long ch(int x, int y) {
	return 1ll * fc[y] * ifc[x] % mod * ifc[y - x] % mod;
}
int main() {
	long long n, a, b, k, ans = 0;
	cin >> n >> a >> b >> k;
	getFc();
	for (int i = 0; i <= n; i++) {
		long long rn = k - i * a;
		if (rn >= 0 && rn % b == 0 && rn / b <= n)
			ans = (ans + 1ll * ch(i, n) * ch(rn / b, n) % mod) % mod;
	}
	cout << ans;
}
