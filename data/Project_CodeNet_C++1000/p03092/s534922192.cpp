#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A, B, INF = 10000000000000;
	vector<long long> P, DP;
	cin >> N >> A >> B;
	P.resize(N);
	DP.assign(N + 1, INF);
	DP[0] = 0;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			if (DP[j] >= INF || j == P[i]) continue;
			if (j < P[i]) {
				DP[P[i]] = min(DP[P[i]], DP[j]);
				DP[j] += A;
			}
			else {
				DP[j] += B;
			}
		}
	}
	long long ANS = INF;
	for (int i = 0; i <= N; i++) {
		ANS = min(ANS, DP[i]);
	}
	cout << ANS << endl;
}