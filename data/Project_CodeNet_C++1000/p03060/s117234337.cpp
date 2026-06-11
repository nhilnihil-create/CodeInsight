#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	vector<int>V(N);
	for (int n = 0;n<N;++n) {
		cin >> V[n];
	}	
	vector<int>C(N);
	for (int n = 0; n < N; ++n) {
		cin >> C[n];
	}	
	for (int n = 0; n < N; ++n) {
		if (V[n]-C[n]>0) {
			ans += V[n] - C[n];
		}
	}
	cout << ans << endl;
	return 0;
}