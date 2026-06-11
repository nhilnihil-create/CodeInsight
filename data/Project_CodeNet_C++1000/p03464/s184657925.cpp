#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	cin >> K;
	vector<long long> A(K);
	for (int i = 0; i < K; i++) cin >> A[i];
	if (A[K - 1] != 2) {
		cout << -1 << endl;
		return 0;
	}
	long long MAX = 3, MIN = 2;
	for (int i = K - 2; i >= 0; i--) {
		if (MIN % A[i]) MIN += A[i] - MIN % A[i];
		MAX -= MAX % A[i];
		if (MIN > MAX) {
			cout << -1 << endl;
			return 0;
		}
		MAX += A[i] - 1;
	}
	cout << MIN << " " << MAX << endl;
}