#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <cmath>
//#include <iomanip>
//#include <map>
//#include <unordered_map>
//#include <cstring>
#include <queue>

using namespace std;
using ll = long long;
using pint = pair<int, int>;
// ll INF = 1LL << 60;

int dh[4] = { 1, 0, -1, 0 };
int dw[4] = { 0, 1, 0, -1 };

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> dist(H, vector<int>(W, -1));
	vector<string> field(H);
	int white = 0;
	for (int h = 0; h < H; h++) cin >> field[h];
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (field[h][w] == '.') white++;
		}
	}
	queue<pint> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 1;

	while (!q.empty()) {
		pint hw = q.front();
		int h = hw.first;
		int w = hw.second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nh = h + dh[dir];
			int nw = w + dw[dir];
			if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
			if (dist[nh][nw] != -1) continue;
			if (field[nh][nw] == '#') continue;
			q.push(make_pair(nh, nw));
			dist[nh][nw] = dist[h][w] + 1;
		}
	}
	if (dist[H - 1][W - 1] == -1) cout << -1 << endl;
	else cout << white - dist[H - 1][W - 1] << endl;
	return 0;
}