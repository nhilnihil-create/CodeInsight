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

	// 0からMまで
	for (int i = 0; i < M; i++) {
		// A[i]がX未満なら
		if (A[i] < X) sum_zero++;
		// A[i]がX以上なら
		else sum_N++;
	}
	cout << min(sum_N, sum_zero) << "\n";
}