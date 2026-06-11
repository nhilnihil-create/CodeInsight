#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, C;
	cin >> N >> C;
	vector<vector<int>> D(C, vector<int>(C)), c(N, vector<int>(N));
	for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) cin >> D[i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> c[i][j];

	int MIN = 500 * 500 * 1000;

	vector<vector<int>> Changes(3, vector<int>(C));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int Col = 0; Col < C; Col++) {
				Changes[(i + j) % 3][Col] += D[c[i - 1][j - 1] - 1][Col];
			}
		}
	}
	int Col[3];
	for (Col[0] = 0; Col[0] < C; Col[0]++) {
		for (Col[1] = 0; Col[1] < C; Col[1]++) {
			if (Col[0] == Col[1]) continue;
			for (Col[2] = 0; Col[2] < C; Col[2]++) {
				if (Col[0] == Col[2] || Col[1] == Col[2]) continue;
				MIN = min(MIN, Changes[0][Col[0]] + Changes[1][Col[1]] + Changes[2][Col[2]]);
			}

		}
	}
	cout << MIN << endl;
}