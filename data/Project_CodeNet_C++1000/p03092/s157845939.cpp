#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A, B, INF = 1000000000000000000;
	cin >> N >> A >> B;
	vector<long long> P(N);
	vector<vector<long long> > DP(N + 1, vector<long long>(N + 1, INF));
	DP[0][0] = 0;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			if (DP[i][j] >= INF) continue;
			if (j < P[i]) {
				DP[i + 1][P[i]] = min(DP[i + 1][P[i]], DP[i][j]);
				DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + A);
			}
			else {
				DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + B);
			}
		}
	}
	long long ANS = INF;
	for (int i = 0; i <= N; i++) {
		ANS = min(ANS, DP[N][i]);
	}
	cout << ANS << endl;
}