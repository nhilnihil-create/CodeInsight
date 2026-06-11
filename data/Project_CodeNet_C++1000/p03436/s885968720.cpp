#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;
struct Point {
	ll x, y;
	Point(){}
	Point(ll xx, ll yy): x(xx), y(yy){}
};


int main() {
	ll h, w;
	cin >> h >> w;
	vector<vector<bool>> grid;
	grid.resize(h);
	vector<vector<ll>> distance;
	distance.resize(h);
	ll numTrue = 0;
	for (ll i = 0; i < h; i++) {
		grid[i].resize(w);
		distance[i].resize(w);
		string str;
		cin >> str;
		for (ll j = 0; j < w; j++) {
			if (str[j] == '.') {
				grid[i][j] = true;
				numTrue++;
			}
			distance[i][j] = -1;
		}
	}
	queue<Point> Q;
	Q.push(Point(0, 0));
	distance[0][0] = 0;
	while (!Q.empty()) {
		Point now = Q.front();
		Q.pop();
		ll nowDis = distance[now.x][now.y];
		Point tmp[4];
		for (ll i = 0; i < 4; i++) {
			tmp[i] = now;
		}
		tmp[0].x++;
		tmp[1].x--;
		tmp[2].y++;
		tmp[3].y--;
		for (ll i = 0; i < 4; i++) {
			if (0 <= tmp[i].x && tmp[i].x < h && 0 <= tmp[i].y && tmp[i].y < w && distance[tmp[i].x][tmp[i].y] == -1 && grid[tmp[i].x][tmp[i].y] == true) {
				distance[tmp[i].x][tmp[i].y] = nowDis + 1;
				Q.push(tmp[i]);
			}
		}
	}
	if (distance[h - 1][w - 1] == -1) {
		cout << -1 << endl;
	}
	else {
		cout << numTrue - distance[h - 1][w - 1] - 1 << endl;
	}
}
