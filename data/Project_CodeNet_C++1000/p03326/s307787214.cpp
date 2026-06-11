#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<long long>>XYZ(N);
	for (int i = 0; i < N; ++i) {
		long long x, y, z;
		cin >> x >> y >> z;
		XYZ[i].push_back(x);
		XYZ[i].push_back(y);
		XYZ[i].push_back(z);
	}
	long long ans = 0;
	for (int i = 0; i < (1 << 3); ++i) {
		vector<long long>P(N);
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 3; ++k) {
				if ((i >> k) & 1) {
					P[j] += XYZ[j][k];
				}
				else {
					P[j] -= XYZ[j][k];
				}
			}
		}
		std::sort(P.rbegin(), P.rend());
		long long anstmp = 0;
		for (int j = 0; j < M; ++j) {
			anstmp += P[j];
		}
		ans = max(ans, anstmp);
	}
	cout << ans << endl;
	return 0;
}
