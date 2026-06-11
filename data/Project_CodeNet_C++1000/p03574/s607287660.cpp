#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

string s[55];

int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		cin >> s[i];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') {
				int cnt = 0;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						int ni = i + k;
						int nj = j + l;
						if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
						if (s[ni][nj] == '#') cnt++;
					}
				}
				s[i][j] = cnt + '0';
			}
		}
	}

	for (int i = 0; i < h; i++)
		cout << s[i] << endl;
}