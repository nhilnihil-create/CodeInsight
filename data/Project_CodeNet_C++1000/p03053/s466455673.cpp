#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> grid(h,vector<char>(w));
	queue<vector<int>> black;
	vector<vector<int>> dist(h, vector<int>(w, -1));
	
	rep(i, h)
		rep(j, w) {
		cin >> grid[i][j];
		if (grid[i][j] == '#') {
			black.push({ i, j });
			dist[i][j] = 0;
		}
		}
	
	int distance = 0;
	while(black.size()){
		int y = black.front()[0];
		int x = black.front()[1];
		black.pop();
		distance = dist[y][x];

		for(int i=0;i<4;i++){
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			if (new_y < 0 || new_y >= h || new_x < 0 || new_x >= w)
				continue;
			if (dist[new_y][new_x] == -1) {
				dist[new_y][new_x] = distance + 1;
				black.push({ new_y,new_x });
			}
		}
	}
	cout << distance << endl;

	return 0;
}