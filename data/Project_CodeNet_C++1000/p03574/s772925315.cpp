#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int h, w;
	char s[60][60];


	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	int c[8][2] = {
		{-1,-1},
		{-1,0 },
		{-1,1},
		{0,1},
		{1,1},
		{1,0},
		{1,-1},
		{0,-1}
	};

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') {
				int mine = 0;
				for (int k = 0; k < 8; k++) {
					int y = i + c[k][0];
					int x = j + c[k][1];
					if (0 <= y && y <= h
						&& 0 <= x && x <= w) {
						if (s[y][x] == '#') mine++;
					}
				}
				s[i][j] = '0' + mine;
			}
		}


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << s[i][j];
		}
		cout << '\n';
	}
}