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

	int c[4][2] = {
		{-1,0 },
		{0,1},
		{1,0},
		{0,-1}
	};

	bool can = true;
	for (int i = 0; i < h; i++)
		for (int j = 0; j <= w; j++) {
			if (s[i][j] == '#') {
				bool can2 = false;
				for (int k = 0; k < 4; k++) {
					int y = i + c[k][0];
					int x = j + c[k][1];
					if (0 <= y && y <= h
						&& 0 <= x && x <= w) {
						if (s[y][x] == '#') can2 = true;
					}
				}
				if (!can2) can = false;
			}
		}


	if (can) cout << "Yes";
	else cout << "No";
}