#include <iostream>
#include <vector>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
	vector<vector<int>> Ans;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] % 2 == 1) {
				if (i < H - 1) {
					Ans.push_back({ i + 1, j + 1, i + 2, j + 1 });
					A[i + 1][j]++;
				}
				else {
					if (j < W - 1) {
						Ans.push_back({ i + 1, j + 1, i + 1, j + 2 });
						A[i][j + 1]++;
					}
				}
			}
		}
	}
	cout << Ans.size() << endl;
	for (int i = 0; i < Ans.size(); i++) cout << Ans[i][0] << " " << Ans[i][1] << " " << Ans[i][2] << " " << Ans[i][3] << endl;
}