#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dx[] = { -1,-1,-1,0,0,1,1,1 }, dy[] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	int h, w; cin >> h >> w;
	vector<string>s(h);
	for (int i = 0; i < h; i++) {
		string tmp; cin >> tmp;
		s[i] = tmp;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') {
				int cnt = 0;
				for (int xy = 0; xy < 8; xy++) {
					int ni = dx[xy] + i;
					int nw = dy[xy] + j;
					if (0 <= ni && ni < h && 0 <= nw && nw < w) {
						if (s[ni][nw] == '#')cnt++;
					}
				}
				cout << cnt;
			}
			else cout << s[i][j];
		}
		cout << endl;
	}

	return 0;
}