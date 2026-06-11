#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,K;
	cin >> N>>K;
	vector<int>H(N);
	for (int n = 0;n<N;++n) {
		cin >> H[n];
	}
	sort(H.begin(),H.end());
	int ans = 1e9;
	for (int n = 0;n<N+1-K;++n) {
		ans = min(ans, H[n + K - 1] - H[n]);
	}
	cout << ans <<endl;
	return 0;
}