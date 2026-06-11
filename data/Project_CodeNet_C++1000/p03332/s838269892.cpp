#include "bits/stdc++.h"
using namespace std;

static long long Fac[300010], MOD = 998244353;

void FacInit(int n) {
	Fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		Fac[i] = Fac[i - 1] * i;
		Fac[i] = Fac[i] % MOD;
	}
}

long long Calc(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		long long c = Calc(a, b / 2);
		return (c * c) % MOD;
	}
	return (a * Calc(a, b - 1)) % MOD;
}

int main() {
	long long N, A, B, K, ans = 0;
	cin >> N >> A >> B >> K;
	FacInit(N);
	for (long long a = 0; a <= N; a++) {
		if (K - A * a < 0) break;
		if ((K - A * a) % B != 0) continue;
		long long b = (K - A * a) / B;
		if (b > N) continue;
		long long nCa = 1, nCb = 1;
		nCa *= Calc(Fac[a], MOD - 2); nCa = nCa % MOD;
		nCa *= Calc(Fac[N - a], MOD - 2); nCa = nCa % MOD;
		nCa *= Fac[N]; nCa = nCa % MOD;
		nCb *= Calc(Fac[b], MOD - 2); nCb = nCb % MOD;
		nCb *= Calc(Fac[N - b], MOD - 2); nCb = nCb % MOD;
		nCb *= Fac[N]; nCb = nCb % MOD;
		ans += (nCa * nCb) % MOD;
		ans = ans % MOD;
	}
	cout << ans;
}