#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>H(N);
	vector<vector<int>> data(100, vector<int>(N));
	for (int n = 0;n<N;++n) {
		cin >> H[n];
		for (int m = 0;m<H[n];++m) {
			data[m][n] = 1;
		}
	}
	int ans = 0;
	for (int n = 0; n < 100; ++n) {
		for (int m = 0;m<N;++m) {
			if (0 ==  m) {
				ans += data[n][m];
			}
			else {
				if (0== data[n][m - 1] && 1 == data[n][m]) {
					ans++;
				}
			}
		}
	}
	cout << ans <<endl;
	return 0;
}
