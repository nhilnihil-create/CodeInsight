#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, T, A;
	cin >> N >> T >> A;
	vector<int>H(N);
	double dans = 1e9;
	int ans = 0;
	for (int n = 0;n<N;++n) {
		cin >> H[n];   
		double tmp = T - H[n] * 0.006;
		double delta = abs(tmp - A);
		if (dans > delta) {
			dans = delta;
			ans = n + 1;
		}
	}
	cout << ans << endl;
	return 0;
}