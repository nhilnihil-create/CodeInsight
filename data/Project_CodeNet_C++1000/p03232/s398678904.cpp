#include "bits/stdc++.h"
using namespace std;

static long long R[100010] = {}, RS[100010] = {}, MOD = 1000000007;

long long Calc(long long A, long long B) {
	if (B == 0) return 1;
	if (B % 2 == 0) {
		long long C = Calc(A, B / 2);
		return (C * C) % MOD;
	}
	return (A * Calc(A, B - 1)) % MOD;
}

void init(long long N) {
	for (int i = 1; i <= N; i++) R[i] = Calc(i, MOD - 2);
	for (int i = 1; i <= N; i++) RS[i] = (RS[i - 1] + R[i]) % MOD;
}

int main() {
	static long long N, A[100000], ANS = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	init(N);
	for (int i = 0; i < N; i++) {
		ANS = (ANS + A[i] * (RS[i + 1] + RS[N - i] + MOD - 1) % MOD) % MOD;
	}
	for (int i = 1; i <= N; i++) {
		ANS = (ANS * i) % MOD;
	}
	cout << ANS << endl;
}