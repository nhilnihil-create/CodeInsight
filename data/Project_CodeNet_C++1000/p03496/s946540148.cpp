#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int nmin = 1e9;
	int nmax = -1e9;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		nmin = min(nmin, A[i]);
		nmax = max(nmax, A[i]);
	}
	cout << 2 * N - 1 << endl;
	if (abs(nmin) >= abs(nmax)) {
		int i;
		for (i = 0; i < N; ++i) {
			if (nmin == A[i]) {
				break;
			}
		}
		for (int j = 0; j < N; ++j) {
			cout << i + 1 << " " << j + 1 << endl;
		}
		for (int j = 0; j < N - 1; ++j) {
			cout << N - j << " " << N - j - 1 << endl;
		}
	}
	else {
		int i;
		for (i = 0; i < N; ++i) {
			if (nmax == A[i]) {
				break;
			}
		}
		for (int j = 0; j < N; ++j) {
			cout << i + 1 << " " << j + 1 << endl;
		}
		for (int j = 0; j < N - 1; ++j) {
			cout << j + 1 << " " << j + 2 << endl;
		}
	}

	return 0;
}