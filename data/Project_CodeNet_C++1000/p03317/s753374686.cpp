#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,K;
	cin >> N>>K;
	vector<int>A(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i];
	}
	int ans = (N-1)/(K-1);
	if (0 != (N-1)%(K-1)) {
		ans++;
	}
	cout << ans <<  endl;
}
