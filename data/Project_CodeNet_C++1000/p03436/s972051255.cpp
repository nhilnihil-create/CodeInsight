#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int n = 0; n < H; ++n) {
		cin >> S[n];
	}
	int count = 0;
	for (int i = 0;i<H;++i) {
		for (int j = 0;j<W;++j) {
			if ('.' == S[i][j]) {
				count++;
			}
		}
	}

	const int dx[] = { -1,0,1,0 };
	const int dy[] = { 0,-1,0,1 };

	int nAns = 0;
	vector<vector<int>> data(H, vector<int>(W, -1));
	data[0][0] = 1;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//範囲内かつ0を4セット
		for (int l = 0; l < 4; ++l) {
			int x1 = x + dx[l];
			int y1 = y + dy[l];
			if ((0 <= x1) && (H > x1) && (0 <= y1) && (W > y1) && (-1 == data[x1][y1]) && ('#' != S[x1][y1])) {
				data[x1][y1] = data[x][y] + 1;
				q.emplace(x1, y1);
			}
		}
	}
	if (-1 == data[H-1][W-1]) {
		cout << -1<<endl;
		return 0;
	}
	cout << count -data[H-1][W-1] << endl;

	return 0;
}