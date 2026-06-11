#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W ;
	vector<string> map(H);
	for (int i = 0; i < H; i++) {
		cin >> map[i];
	}
	int str = 1;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 }; 
	int count = 0;
	queue<int> quex;
	queue<int> quey;
	vector<vector<int>>dict(H, vector<int>(W, -1));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '#') {
				quex.push(j);
				quey.push(i);
				dict[i][j] = 0;
			}
		}
	}
	
	while (!quex.empty() && !quey.empty()) {
		bool flag = false;
		int x = quex.front();
		int y = quey.front();
		quex.pop();
		quey.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i]; 
			if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
			if (map[ny][nx]=='.') {
				dict[ny][nx] = dict[y][x] + 1;
				quex.push(nx);
				quey.push(ny);
				map[ny][nx] = '#';
				flag = true;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (count < dict[i][j]) {
				count = dict[i][j];
			}
		}
	}
	std::cout << count << endl;
}