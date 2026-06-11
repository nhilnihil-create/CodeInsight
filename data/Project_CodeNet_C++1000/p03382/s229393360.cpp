#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int maxN = *max_element(A.begin(), A.end());
	int maxR = 0;
	int bestR = 0;
	for (int i = 0; i < N; i++) {
		int r = min(A[i], maxN-A[i]);
		if (r > maxR) {
			maxR = r;
			bestR = A[i];
		}
	}
	cout << maxN << ' ' << bestR << '\n';

	return 0;
}