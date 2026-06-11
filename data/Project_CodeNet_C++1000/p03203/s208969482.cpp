#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int H, W, N;
vector<vector<int>> field;

int main() {
	cin >> H >> W >> N;
	field.resize(H);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x >= y) {
			field[x].push_back(y);
		}
	}

	int ans = H - 1;
	int wlimit = 0;
	
	for (int i = 0; i < H; i++)sort(field[i].begin(), field[i].end());
	for (int i = 1; i < H; i++) {
		if (field[i].size() == 0)wlimit++;
		else {
			if (field[i][0] <= wlimit) {
				cout << i << endl;
				return 0;
			}
			else if (field[i][0] == wlimit + 1) {
				//cannot do anything
			}
			else {
				wlimit++;
			}
		}
	}

	cout << ans + 1 << endl;
	return 0;
}
