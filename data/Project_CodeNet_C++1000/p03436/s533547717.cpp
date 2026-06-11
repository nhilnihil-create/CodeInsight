#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
#include <cstring>
typedef long long ll;
typedef long double ld;

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
using Graph = vector<vector<int>>;
/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
ll H, W;
ll sX, sY, gX, gY;
char maze[100];
bool reached[100];
ll sectin = 0;
ll flg = true;
vector<string>field;
ll cheese;
vector<pair<int,int>>cheeseList;
int main() {
	cin >> H >> W;
	field = vector<string>(H);
	ll sharp = 0;
	rep(i,H) {
		cin >> field[i];
		rep(j,W) {
			if (field[i][j]=='#') {
				sharp++;
			}
		}
	}
	Graph dist(H, vector<int>(W, -1));
	queue<pair<int, int>> que;
	dist[0][0] = 0;
	que.push(make_pair(0, 0));

	while (!que.empty()) {
		pair<int, int>pos = que.front();
		int x = pos.first;
		int y = pos.second;
		que.pop();

		rep(direction, 4) {
			int nextX = x + dx[direction];
			int nextY = y + dy[direction];
			if (nextX < 0 || H <= nextX || nextY < 0 || W <= nextY)continue;
			if (field[nextX][nextY] == '#')continue;

			if (dist[nextX][nextY] == -1) {
				que.push(make_pair(nextX, nextY));
				dist[nextX][nextY] = dist[x][y] + 1;
			}
		}
	}
	if (dist[H - 1][W - 1]!=-1) {
		ll ans = H * W - (sharp + dist[H-1][W-1]+1);
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}