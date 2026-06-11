#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
using LL = long long;
using Graph = vector<vector<int>>;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> G(H + 2, vector<int>(W + 2, -1));
	int white_num = 0;
 	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char a;
			cin >> a;
			if (a == '.') {
				G[i][j] = 1;
				white_num++;
			}
		}
	}

	if (G[1][1] == -1 || G[H][W] == -1) {
		cout << -1 << endl;
		return 0;
	}


	queue<pair<int, int>> que;
	vector<vector<int>> dist(H + 2, vector<int>(W + 2, -1));
	que.push(make_pair(1, 1));
	dist[1][1] = 1;

	while (!que.empty()) {
		pair<int, int> p =que.front();
		que.pop();
		int _x = p.first;
		int _y = p.second;
		if (G[_x + 1][_y] == 1 && dist[_x + 1][_y] == -1) {
			que.push(make_pair(_x + 1, _y));
			dist[_x + 1][_y] = dist[_x][_y] + 1;
		}
		if (G[_x - 1][_y] == 1 && dist[_x - 1][_y] == -1) {
			que.push(make_pair(_x - 1, _y));
			dist[_x - 1][_y] = dist[_x][_y] + 1;
		}
		int u = G[_x][_y + 1];
		if (G[_x][_y + 1] == 1 && dist[_x][_y+1] == -1) {
			que.push(make_pair(_x, _y + 1));
			dist[_x][_y + 1] = dist[_x][_y] + 1;
		}
		if (G[_x][_y - 1] == 1 && dist[_x][_y-1] == -1) {
			que.push(make_pair(_x, _y - 1));
			dist[_x][_y - 1] = dist[_x][_y] + 1;
		}
	}
	int temp = dist[H][W];
	if (temp == -1) {
		cout << -1 << endl;
		return 0;
	}
	int ans = white_num - temp;
	cout << ans << endl;
	return 0;
}