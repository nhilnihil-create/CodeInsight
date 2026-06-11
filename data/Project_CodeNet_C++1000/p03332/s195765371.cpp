#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int f1(int a, int p) {
	if (p == 1)return a;
	if (p % 2)return f1(a, p - 1) * a % mod;
	else return f1(a * a % mod, p / 2) % mod;
}
int c[345678], n, a, b, k, ans = 0;
signed main() {
	cin >> n >> a >> b >> k;
	c[0] = 1;
	for1(i, n) {
		c[i] = c[i - 1] * (n - i + 1) % mod;
		c[i] = c[i] * f1(i, mod - 2) % mod;
	}
	for0(i, n + 1) {
		if (a * i > k)break;
		if ((k - a * i) % b == 0 && (k - a * i) / b <= n) {
			ans += c[i] * c[(k - a * i) / b]; ans %= mod;
		}
	}
	cout << ans << endl;
}