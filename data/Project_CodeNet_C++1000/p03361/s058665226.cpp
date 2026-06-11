#include<bits/stdc++.h>
using namespace std;

int H, W;
vector<string> s(55);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
	bool ok = true;
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
		if (s[i][j] == '.') continue;
		bool sub_ok = false;
		for (int k = 0; k < 4; k++) {
			int y = i + dy[k];
			int x = j + dx[k];
			if (y < 0 || y >= H || x < 0 || x >= W) continue;
			if (s[y][x] == '#') sub_ok = true;
		}
		if (!sub_ok) ok = false;
	}
	cout << (ok ? "Yes" : "No") << endl;
}

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; ++i) cin >> s[i];
	solve();

	return 0;
}