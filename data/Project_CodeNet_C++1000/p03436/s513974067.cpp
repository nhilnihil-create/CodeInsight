#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;

void maze_search(int H,int W,int sx,int sy,vector<vector<char>> maze, vector<vector<int>> &dist) {
	//壁は#で定義
	queue<pair<int, int>> position;
	dist[sy][sx] = 0;

	int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };//探索方向

	position.push(make_pair(sy, sx));

	while (!position.empty()) {
		pair<int, int> current_pos = position.front(); 
		int x = current_pos.second;
		int y = current_pos.first;
		position.pop();
		for (int direction = 0; direction < 4; direction++) {
			int x_next = x + dx[direction];
			int y_next = y + dy[direction];
			if (x_next < 0 || x_next >= W || y_next < 0 || y_next >= H)continue;
			if (maze[y_next][x_next] == '#')continue;
			if (dist[y_next][x_next] == -1) {
				position.push(make_pair(y_next, x_next));
				dist[y_next][x_next] = dist[y][x] + 1;
			}
		}
	}
}

int main() {
	int H, W; cin >> H >> W;
	vector<vector<char>> maze(H,vector<char>(W));
	for (int i = 0; i < H; i++)for(int j=0;j<W;j++)cin >> maze[i][j];
	vector<vector<int>>dist(H, vector<int>(W, -1));
	int count_wall = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (maze[i][j] == '#')count_wall++;
		}
	}
	queue<pair<int, int>> position;
	dist[0][0] = 0;
	position.push(make_pair(0, 0));//start_positon

	maze_search(H, W, 0, 0, maze, dist);

	if (dist[H - 1][W - 1] == -1) {
		cout << "-1" << endl;
	}
	else {
		int ans = H * W - 1 - dist[H - 1][W - 1] - count_wall;
		cout << ans << endl;
	}
}