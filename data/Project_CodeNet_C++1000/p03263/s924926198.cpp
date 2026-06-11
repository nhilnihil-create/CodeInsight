#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> v(h + 1, vector<int>(w + 1, 0));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<int>> res;
	int valid = 0;
	int coin = 0;
	int lx = 0, ly = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int x = i, y = j;
			if (x % 2 == 0) y = w + 1 - j;
			if (v[x][y] % 2 == 1) {
				coin = 1 - coin;
				if (coin == 0) res.push_back({lx, ly, x, y});
				if (coin == 0) valid = res.size();
			} else {
				if (coin == 1) res.push_back({lx, ly, x, y});
			}
			lx = x, ly = y;
		}
	}
	cout << valid << endl;
	for (int i = 0; i < valid; i++) {
		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << endl;
	}
}
