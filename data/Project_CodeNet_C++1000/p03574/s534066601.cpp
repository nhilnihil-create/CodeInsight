#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	rep(y, h) rep(x, w) {
		if (s[y][x] == '#') continue;
		int cnt = 0;
		for (int dy = -1; dy <= 1; dy++) {
			for (int dx = -1; dx <= 1; dx++) {
				int ny = y + dy;
				int nx = x + dx;
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (s[ny][nx] == '#') cnt++;
			}
		}
		s[y][x] = cnt + '0';
	}
	rep(i, h) cout << s[i] << endl;
	return 0;
}