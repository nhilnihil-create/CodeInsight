#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<vector<int>> dir4 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<bool>> grid(h + 2, vector<bool>(w + 2, true));
	vector<vector<int>> dist(h + 2, vector<int>(w + 2, 0));
	queue<pair<int,int>> que;

	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			char c; cin >> c;
			grid[i][j] = (c == '#');
			if(c == '#') {
				que.emplace(i, j);
			}else {
				dist[i][j] = -1;
			}
		}
	}

	while(que.size()) {
		auto cur = que.front(); que.pop();
		for(auto d : dir4) {
			if(dist[cur.first + d[0]][cur.second + d[1]] != -1)continue;
			dist[cur.first + d[0]][cur.second + d[1]] = dist[cur.first][cur.second] + 1;
			que.emplace(cur.first + d[0], cur.second + d[1]);
		}
	}

	//for(int i = 1; i <= h; i++) {for(int j = 1; j <= w; j++)cout << dist[i][j] << " "; cout << endl;}

	int nax = 0;
	for(int i = 0; i <= h; i++) {
		nax = max(nax, *max_element(dist[i].begin(), dist[i].end()));
	}
	cout << nax << endl;
}