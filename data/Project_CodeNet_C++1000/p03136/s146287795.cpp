#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>L(N);
	int sum = 0;
	int maxsize = 0;
	for (int n = 0; n < N; ++n) {
		cin >> L[n];
		sum += L[n];
		maxsize = max(maxsize,L[n]);
	}
	if (sum > maxsize*2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}