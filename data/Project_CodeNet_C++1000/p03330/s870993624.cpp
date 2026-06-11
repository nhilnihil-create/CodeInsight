#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, C;
	cin >> N >> C;
	vector<vector<int> > D(C, vector<int>(C));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> D[i][j];
		}
	}
	vector<vector<int> > A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j]; --A[i][j];
		}
	}
	vector<vector<int> > val(3, vector<int>(C));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < C; ++k) {
				val[(i + j) % 3][k] += D[A[i][j]][k];
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			for (int k = 0; k < C; ++k) {
				if (i != j && j != k && k != i) {
					ans = min(ans, val[0][i] + val[1][j] + val[2][k]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}