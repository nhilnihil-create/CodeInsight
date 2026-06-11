#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w; cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	vector<pair<int, int>> from, to;
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] % 2 != 0) {
				a[i][j]--;
				a[i + 1][j]++;
				from.push_back({ i + 1,j + 1 });
				to.push_back({ i + 2,j + 1 });
				cnt++;
			}
		}
	}
	for (int j = 0; j < w - 1; j++) {
		if (a[h - 1][j] % 2 != 0) {
			a[h - 1][j]--;
			a[h - 1][j + 1]++;
			from.push_back({ h,j + 1 });
			to.push_back({ h,j + 2 });
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < from.size(); i++) {
		cout << from[i].first << " " << from[i].second << " " << to[i].first << " " << to[i].second << endl;
	}
	return 0;
}