#include<iostream>
#include<vector>
using namespace std;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int main() {
	int h, w; cin >> h >> w;
	vector<string>s(h);
	for (int i = 0; i < h; i++) {
		string tmp; cin >> tmp;
		s[i] = tmp;
	}

	bool ok = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				bool black = false;
				for (int k = 0; k < 4; k++) {
					int nx = dx[k] + i, ny = dy[k] + j;
					if (0 <= nx && nx < h && 0 <= ny && ny < w) {
						if (s[nx][ny] == '#')black = true;
					}
				}
				if (!black)ok = false;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}