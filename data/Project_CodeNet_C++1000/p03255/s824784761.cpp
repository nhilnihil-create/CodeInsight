#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, X;
	cin >> N >> X;
	vector<long long> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	reverse(A.begin(), A.end());
	vector<long long> SUM(N + 1, 0);
	for (int i = 0; i < N; i++) SUM[i + 1] = SUM[i] + A[i];
	long long ANS = 1000000000000000000;
	for (long long K = N; K >= 1; K--) {
		long long NOW = 0;
		long long COUNT = 0;
		while (1) {
			long long L = NOW * K, R = L + K;
			long long P;
			if (NOW == 0) P = 5;
			else P = NOW * 2 + 3;
			if (R > N) {
				COUNT += (SUM[N] - SUM[L]) * P;
				break;
			}
			COUNT += (SUM[R] - SUM[L]) * P;
			NOW++;
			if (COUNT > ANS) goto NEXT;
		}
		ANS = min(ANS, X * K + X * N + COUNT);
	NEXT:;
	}
	cout << ANS << endl;
}