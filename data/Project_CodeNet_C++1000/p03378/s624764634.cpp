#include <iostream>

using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	int A[100];
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	int sum_zero = 0;
	int sum_N = 0;

	// XからNまで
	for (int i = X; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[j] == i) {
				sum_N += 1;
				break;
			}		
		}
	}

	// Xから0まで
	for (int i = X; i > 0; i--) {
		for (int j = 0; j < M; j++) {
			if (A[j] == i) {
				sum_zero += 1;
				break;
			}		
		}
	}

	cout << min(sum_N, sum_zero) << "\n";
}