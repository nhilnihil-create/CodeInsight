#include "bits/stdc++.h"
using namespace std;

int main() {
	vector<int>A(5);
	int sum = 0;
	int memo = 10;
	for (int n = 0;n<5;++n) {
		cin >> A[n];
		if (0 == A[n]%10) {
			sum += A[n];
		}
		else {
			sum += (A[n] / 10 + 1) * 10;
		}
		if (0 != A[n]%10) {
			memo = min(memo, A[n] % 10);
		}
	}	
	if (10!= memo) {
		sum -= (10 - memo);
	}
	cout << sum << endl;
	return 0;
}