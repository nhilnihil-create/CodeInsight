#include "bits/stdc++.h"
using namespace std;

//素数判定
bool prime(long long  n) {
	if (1 == n) {
		return false;
	}
	for (long long i = 2; i*i <= n; i++) {
		if (0 == n % i) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int>P;
	int now = 1;
	while (N != P.size()) {
		if (prime(now)) {
			P.push_back(now);
		}
		now += 5;
	}
	for (int i = 0; i < N; ++i) {
		if (0 != i) {
			cout << " ";
		}
		cout << P[i];
	}
	return 0;
}
