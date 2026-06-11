#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	vector<vector<int>> d(C, vector<int>(C));
	vector<vector<int>> c(N, vector<int>(N));
	vector<vector<int>> data(3, vector<int>(C));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> c[i][j];
			data[(i + j) % 3][c[i][j]-1]++;
		}
	}
	long long ans = 1e18;
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			for (int k = 0; k < C; ++k) {
				long long anstmp = 0;
				if (i == j) {
					continue;
				}
				if (j == k) {
					continue;
				}
				if (i == k) {
					continue;
				}
				//cout << i << j<<k << endl;
				for (int l = 0; l < C; ++l) {
					anstmp += d[l][i] * data[0][l];
				}
				for (int l = 0; l < C; ++l) {
					anstmp += d[l][j] * data[1][l];
				}
				for (int l = 0; l < C; ++l) {
					anstmp += d[l][k] * data[2][l];
				}
				ans = min(ans ,anstmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
