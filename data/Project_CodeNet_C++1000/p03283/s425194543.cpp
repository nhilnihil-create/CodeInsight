#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> L(M);
	vector<int> R(M);
	vector<int> p(Q);
	vector<int> q(Q);
	for (int i = 0; i < M; i++) cin >> L[i] >> R[i];
	for (int i = 0; i < Q; i++) cin >> p[i] >> q[i];

	vector<vector<int>> field(N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		field[L[i] - 1][R[i] - 1]++;
	}

	vector<vector<int>> s(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + field[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		int num = s[q[i]][q[i]] - s[p[i] - 1][q[i]] - s[q[i]][p[i] - 1] + s[p[i] - 1][p[i] - 1];
		cout << num << endl;
	}


	return 0;
}
