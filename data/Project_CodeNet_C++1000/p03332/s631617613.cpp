#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long fac[300030], finv[300030], inv[300030];
long long mod = 998244353;
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < 300030; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long COM(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main() {
	COMinit();
	long long n, a, b, k;
	cin >> n >> a >> b >> k;
	long long ans = 0;
	for (long long i = 0; i <= n; i++) {
		if ((k - i * a) % b == 0) {
			long long co = COM(n, i) * COM(n, (k - i * a) / b);
			co %= 998244353;
			ans += co;
			ans %= 998244353;
		}
	}
	cout << ans << endl;
}
