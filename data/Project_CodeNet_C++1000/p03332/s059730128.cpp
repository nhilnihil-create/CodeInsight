#include <iostream>
#define mod 998244353
using namespace std;
int fac[1000006], inv[1000006];
int fpw(int x, int y){
	int ans = 1;
	for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % mod)
		if (y & i)
			ans = 1LL * ans * x % mod;
	return ans;
}
int C(int n, int m){
	return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(){
	int n, a, b;
	long long k;
	cin >> n >> a >> b >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	inv[n] = fpw(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; -- i)
		inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	int ans = 0;
	for (int i = 0; i <= min(1LL * n, k / a); ++ i)
		if ((k - i * a) % b == 0 && (k - i * a) / b <= n)
			ans = (ans + 1LL * C(n, i) * C(n, (k - i * a) / b) % mod) % mod;
	cout << ans << endl;
}
