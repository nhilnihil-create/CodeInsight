#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m, qq;
	cin >> n >> m >> qq;

	vector<vector<int>> lr(n + 1,vector<int> (n+1));

	int l, r;
	for (int i = 1; i <= m; i++) {

		cin >> l >> r;
		lr[l][r]++;

	}

	vector<vector<int>> lrsum(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			lrsum[i][j] = lrsum[i - 1][j] + lrsum[i][j - 1] - lrsum[i - 1][j - 1] + lr[i][j];

		}
	}

	int p, q;
	for (int i = 0; i < qq; i++) {
		cin >> p >> q;
		
		cout << lrsum[q][q] - lrsum[p - 1][q] - lrsum[q][p - 1] + lrsum[p - 1][p - 1] << endl;;

	}

	return 0;
}