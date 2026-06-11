#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[2000], SUM = 0;
	static bitset<4000010> DP;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i], SUM += A[i];
	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		DP = DP | (DP << A[i]);
	}
	for (long long i = (SUM + 1) / 2; i <= SUM; i++) {
		if (DP[i]) {
			cout << i << endl;
			return 0;
		}
	}
}