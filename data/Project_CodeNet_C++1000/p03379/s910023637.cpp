#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>X(N);
	vector<int>copyX(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		copyX[i] = X[i];
	}
	sort(copyX.begin(), copyX.end());
	for (int i = 0;i<N; ++i) {
		if (X[i] < copyX[N / 2]) {
			cout << copyX[N / 2] << endl;
		}
		else {
			cout << copyX[N / 2 -1] << endl;
		}
	}
	return 0;
}