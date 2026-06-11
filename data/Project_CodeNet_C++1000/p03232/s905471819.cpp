#include <iostream>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n % 2) return (a * powmod(a, n - 1, mod)) % mod;
	return powmod((a * a) % mod, n / 2, mod);
}

int mod = 1000000007;
int n;
int a[100000];
int inv[100001];
int fact[100001];

signed main() {
	int i;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) inv[i + 1] = (inv[i] + powmod(i + 1, mod - 2, mod)) % mod;
	fact[0] = 1;
	rep(i, n) fact[i + 1] = ((i + 1) * fact[i]) % mod;
	
	int ans = 0;
	rep(i, n) {
		ans += (inv[i+1] + inv[n-i] - inv[1]) * a[i];
		ans %= mod;
	}
	ans *= fact[n];
	ans %= mod;
	cout << ans << endl;
	return 0;
}