#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> F(N, vector<int>(10));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> F[i][j];
		}
	}
	vector<vector<int>> P(N, vector<int>(11));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 11; ++j) {
			cin>>P[i][j];
		}
	}
	int ans = -1e9;
	for (int i = 1; i < (1 << 10); ++i) {
		int subans = 0;
		for (int j = 0;j<N;++j) {
			int count = 0;
			for (int k = 0;k<10;++k) {
				if (1 & (i>>k)) {
					if (1 == F[j][k]) {
						count++;
					}
				}
			}
			subans += P[j][count];
		}
		ans = max(ans, subans);
	}
	cout << ans << endl;
	return 0;
}
