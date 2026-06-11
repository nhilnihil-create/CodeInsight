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
using Graph = vector<vector<ll>>;
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

int main() {
	cin >> H >> W;
	field = vector<string>(H);
	Graph status = Graph(H,vector<ll>(W,-1));
	queue<pair<ll, ll>>que;
	rep(i,H) {
		cin >> field[i];
		rep(j,W) {
			if (field[i][j]=='#') {
				status[i][j] = 0;
				que.push(make_pair(i, j));
			}
		}
	}

	ll ans = 0;
	while (!que.empty()) {
		pair<ll, ll>tmp = que.front();
		que.pop();
		ll x = tmp.first;
		ll y = tmp.second;

		rep(directions,4) {
			ll nextX = x + dx[directions];
			ll nextY = y + dy[directions];
			if (nextX < 0 || H <= nextX || nextY < 0 || W <= nextY)continue;
			if (field[nextX][nextY] == '#')continue;

			field[nextX][nextY] = '#';
			status[nextX][nextY] = status[x][y] + 1;
			ans = max(ans, status[nextX][nextY]);
			que.push(make_pair(nextX, nextY));
		}
	}
	cout << ans << endl;
	return 0;
}