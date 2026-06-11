// ABC101C - Minimization

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		int t;
//		cin >> t;
//	}

	int ans;
//	ans = ((N - K) + (K - 2))/ (K - 1) + 1;
	ans = (N - 2)/(K - 1) + 1;

	cout << ans << endl;

	return 0;
}
