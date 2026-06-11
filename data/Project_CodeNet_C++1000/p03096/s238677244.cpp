#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, MOD = 1000000007;
	static long long C[200000], DP[200010] = {}, X[200010] = {};
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	DP[0] = 1;
	X[C[0]] = 1;
	for (int i = 1; i < N; i++) {
		if (C[i] == C[i - 1]) DP[i] = DP[i - 1];
		else DP[i] = (DP[i - 1] + X[C[i]]) % MOD;
		X[C[i]] = DP[i];
	}
	cout << DP[N - 1] << endl;
}