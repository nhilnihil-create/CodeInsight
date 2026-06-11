#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,M,Q;
	cin >> N >> M >> Q;
	vector<vector<int>> data(N + 1, vector<int>(N + 1));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1));
	for (int i = 0;i<M;++i) {
		int L, R;
		cin >> L >> R;
		data[L][R]++;
	}
	for (int i = 0;i<N;++i) {
		for (int j = 0;j<N;++j) {
			sum[i + 1][j + 1] = sum[i + 1][j]+sum[i][j+1]-sum[i][j]+data[i + 1][j + 1];
		}
	}
	for (int i = 0;i < Q;++i) {
		int p, q;
		cin >> p >> q;
		cout << sum[q][q]+sum[p -1 ][p - 1]-sum[p - 1][q]-sum[q][p - 1]<<endl;
	}
	return 0;
}