#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int>> LR(N, vector<int>(N));
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		LR[l - 1][r - 1]++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0) LR[i][j] += LR[i - 1][j];
			if (j > 0) LR[i][j] += LR[i][j - 1];
			if (i > 0 && j > 0) LR[i][j] -= LR[i - 1][j - 1];
		}
	}
	vector<int> Ans(Q);
	for (int i = 0; i < Q; i++) {
		int p, q;
		cin >> p >> q;
		Ans[i] = LR[q - 1][q - 1];
		if (p > 1) Ans[i] += -LR[p - 2][q - 1] - LR[q - 1][p - 2] + LR[p - 2][p - 2];
	}
	for (int a : Ans) cout << a << endl;
}