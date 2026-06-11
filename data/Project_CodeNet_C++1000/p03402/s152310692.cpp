#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int w = 100;
int h = 100;
int f[100][100];

void show() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (f[i][j] == 0) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			f[i][j] = 0;
		}
	}
	a--;
	int x = 0;
	int y = 0;
	int dx[8] = { 0,1,2,2,2,1,0,0 };
	int dy[8] = { 0,0,0,1,2,2,2,1 };
	while (a > 0 && b > 0) {
		for (int d = 0; d < 8; ++d) {
			f[y + dy[d]][x + dx[d]] = 1;
		}
		x += 4;
		if (x+4 >= 100) {
			x = 0;
			y += 4;
		}
		a--;
		b--;
	}
	if (a > 0) {
		x = 0;
		y += 3;
		for (int d = 0; d < 8; ++d) {
			f[y + dy[d]][x + dx[d]] = 1;
		}
		a--;
		y += 3;
		while (a > 0) {
			for (int d = 0; d < 8; ++d) {
				f[y + dy[d]][x + dx[d]] = 1;
			}
			x += 3;
			if (x + 4 >= 100) {
				x = 0;
				y += 3;
			}
			a--;
		}
	}
	while (b > 0) {
		for (int d = 0; d < 8; ++d) {
			f[y + dy[d]][x + dx[d]] = 1;
			f[y + 1][x + 1] = 1;
		}
		x += 4;
		if (x+4 >= 100) {
			x = 0;
			y += 4;
		}
		b--;
	}
	cout << 100 << " " << 100 << endl;
	show();
	return 0;
}