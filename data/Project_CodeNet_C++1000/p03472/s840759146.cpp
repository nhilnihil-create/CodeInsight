#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,H;
	cin >> N >> H;
	vector<int>A(N);
	vector<int>B(N);
	for (int i = 0;i<N;++i) {
		cin >> A[i] >> B[i];
	}
	sort(A.rbegin(),A.rend()); 
	sort(B.rbegin(), B.rend());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (H>0 &&B[i] > A[0]) {
			ans++;
			H -= B[i];
		}
	}
	if (H>0) {
		ans += H / A[0];
		if (0!= H%A[0]) {
			ans++;
		}
	}
	cout << ans <<endl;
	return 0;
}