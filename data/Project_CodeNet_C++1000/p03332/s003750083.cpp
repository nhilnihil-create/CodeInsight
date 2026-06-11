#include <iostream>
using namespace std;

const int N = 300 * 1000 + 5;
const int mod = 998244353;

long long fac[N];
int po(int x, int y) {
	if (y == 0)
		return 1;
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2 == 1) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
int chs(int x, int y) {
	long long ans = fac[x];
	ans *= po(fac[y], mod - 2);
	ans %= mod;
	ans *= po(fac[x - y], mod - 2);
	ans %= mod;
	return ans;
}
int main() {
	int n;
	long long a, b, k, ans = 0;
	cin >> n >> a >> b >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	for (int i = 0; i <= n; i++) {
		long long t = k - 1ll * a * i;
		if (t >= 0 && t % b == 0 && t / b <= n) {
			long long x = chs(n, i);
			x *= chs(n, t / b);
			x %= mod;
			ans += x;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
