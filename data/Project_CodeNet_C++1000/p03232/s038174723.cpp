#include <iostream>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
int kaijo(int n) {
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	return ans;
}
int modpow(int a, int b) {
	if (b == 0)return 1;
	if (b % 2)return modpow(a, b - 1)*a%mod;
	return modpow(a, b / 2)*modpow(a, b / 2) % mod;
}
int n, a[111111], b[111111], ans, k;
signed main() {
	cin >> n;
	k = kaijo(n);
	rep(i, n)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		b[i] = modpow(i, mod - 2);
		b[i] *= k;
		b[i] %= mod;
		b[i] += b[i - 1];
		b[i] %= mod;
	}
	rep(i, n) {
		ans += a[i] * b[n - i] + a[i] * b[i + 1] - a[i] * b[1];
		ans %= mod;
	}
	cout << ans << endl;
	getchar(); getchar(); return 0;
	return 0;
}
