#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <functional>
#include <random>
using namespace std;

const int MOD = 998244353;
const int INF = 999999999;

long long fac[300005], finv[300005], inv[300005];

void COMinit() {
	fac[0] = 1, fac[1] = 1, finv[0] = 1, finv[1] = 1, inv[1] = 1;
	for (int i = 2; i < 300005; ++i) {
		fac[i] = fac[i - 1] * i%MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

//calc
long long COM(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	COMinit();
	long long a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= a; ++i) {
		if ((d - i * b) % c == 0 && (d - i * b) / c <= a) { ans += COM(a, i)*COM(a, (d - i * b) / c); ans %= MOD; }
	}
	cout << max(ans % MOD, (long long)1) << endl;
}