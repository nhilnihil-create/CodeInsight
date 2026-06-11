#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long>X(N);
	vector<long long>Y(N);
	vector<long long>Z(N);
	for (int i = 0;i<N;++i) {
		cin >> X[i] >> Y[i] >> Z[i];
	}
	long long ans = 0;
	for (int i = 0;i <(1<<3);++i) {
		vector<long long>P(N);
		for (int j = 0;j<N;++j) {
			if ((i >> 0)&1) {
				P[j] += X[j];
			}
			else {
				P[j] -= X[j];
			}
			if ((i >> 1) & 1) {
				P[j] += Y[j];
			}
			else {
				P[j] -= Y[j];
			}
			if ((i >> 2) & 1) {
				P[j] += Z[j];
			}
			else {
				P[j] -= Z[j];
			}
		}
		std::sort(P.rbegin(), P.rend());
		long long anstmp = 0;
		for (int j = 0; j < M; ++j) {
			anstmp += P[j];
		}
		ans = max(ans , anstmp);
	}
	cout << ans <<  endl;
	return 0;
}
