#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w; cin >> h >> w;
	vector<vector<char>> c(h + 2, vector<char>(w + 2));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}
	}
	vector<int> dy = { 0,1,0,-1, 1,1,-1  ,-1 };
	vector<int> dx = { 1,0,-1,0, 1,-1,1, -1 };
	const int p = 8;
	vector<vector<int>> c_ans(h + 2, vector<int>(w + 2));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (c[i][j] == '#') {
				cout << c[i][j];
			}
			else {
				int tmpCnt = 0;
				for (int k = 0; k < p; k++) {
					if (c[i + dy[k]][j + dx[k]] == '#') tmpCnt++;
				}
				c_ans[i][j] = tmpCnt;
				cout << c_ans[i][j];
			}			
		}
		cout << endl;
	}
	return 0;
}