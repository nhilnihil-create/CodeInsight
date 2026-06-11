#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}

	int vy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int vx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '.') {
				int count = 0;
				for (int k = 0; k < 8; k++) {
					int y = i + vy[k];
					int x = j + vx[k];
					if (y < 0 || y >= H || x < 0 || x >= W) {
						continue;
					}
					if (S[y][x] == '#') {
						count++;
					}
				}
				S[i][j] = '0' + count;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		cout << S[i] << endl;
	}

	return 0;
}