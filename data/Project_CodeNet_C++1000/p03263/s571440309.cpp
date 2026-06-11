#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int a[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> ans;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			if (a[i][j] & 1) {
				a[i][j]--;
				a[i][j+1]++;
				ans.push_back({i+1, j+1, i+1, j+2});
			}
		}
	}
	for (int i = 0; i < h-1; i++) {
		int j = w-1;
		if (a[i][j] & 1) {
			a[i][j]--;
			a[i+1][j]++;
			ans.push_back({i+1, j+1, i+2, j+1});
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << endl;
	}
	return 0;
}
