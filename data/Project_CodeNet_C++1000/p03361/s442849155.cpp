#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>board(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)cin >> board.at(i).at(j);
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board.at(i).at(j) == '.')continue;
			bool up = false, left = false, right = false, down = false;
			if (i != 0)if (board.at(i - 1).at(j) == '#')up = true;
			if (j != 0)if (board.at(i).at(j - 1) == '#')left = true;
			if (j != w - 1)if (board.at(i).at(j + 1) == '#')right = true;
			if (i != h - 1)if (board.at(i + 1).at(j) == '#')down = true;
			if (!(up || left || right || down)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

}