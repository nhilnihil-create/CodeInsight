#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
int main() {
	//input
	int H, W;
	cin >> H >> W;
	string S[50];
	for (int i = 0; i < H; i++)cin >> S[i];

	//initialize
	int white = 0;
	int cost[50][50];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cost[i][j] = 3000;//big enough
			if (S[i][j] == '.')white++;
		}
	}

	//bfs
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	queue<pair<int, int>>que;
	cost[0][0] = 1;
	que.push(make_pair(0, 0));
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (y + dy[i] < 0 || y + dy[i] >= H || x + dx[i] < 0 || x + dx[i] >= W)continue;
			if (S[y + dy[i]][x + dx[i]] == '#')continue;
			if (cost[y + dy[i]][x + dx[i]] > cost[y][x] + 1) {
				cost[y + dy[i]][x + dx[i]] = cost[y][x] + 1;
				que.push(make_pair(y + dy[i],x + dx[i]));

			}
		}
	}

	//output
	if (cost[H - 1][W - 1] == 3000)cout << -1 << endl;
	else cout << white - cost[H - 1][W - 1] << endl;

	return 0;
}
