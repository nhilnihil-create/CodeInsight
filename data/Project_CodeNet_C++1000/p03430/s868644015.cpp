#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	long long K;
	cin >> S >> K;
	vector<vector<vector<long long> > > DP(K + 1, vector<vector<long long> >(S.size() + 1, vector<long long>(S.size() + 1, 0)));
	for (int k = 0; k <= K; k++) {
		for (int L = 0; L < S.size(); L++) {
			for (int R = S.size(); R > L; R--) {
				if (S[L] == S[R - 1]) DP[k][L + 1][R - 1] = max(DP[k][L + 1][R - 1], DP[k][L][R] + 2);
				else if (k != K) DP[k + 1][L + 1][R - 1] = max(DP[k + 1][L + 1][R - 1], DP[k][L][R] + 2);
				DP[k][L][R - 1] = max(DP[k][L][R - 1], DP[k][L][R]);
				DP[k][L + 1][R] = max(DP[k][L + 1][R], DP[k][L][R]);
				if (k != K) DP[k + 1][L][R] = max(DP[k + 1][L][R], DP[k][L][R]);
			}
		}
	}
	long long ANS = 0;
	for (int L = 0; L < S.size(); L++) {
		for (int R = S.size(); R >= L; R--) {
			ANS = max(ANS, DP[K][L][R]);
			if (R == L + 1) ANS = max(ANS, DP[K][L][R] + 1);
		}
	}
	cout << ANS << endl;
}