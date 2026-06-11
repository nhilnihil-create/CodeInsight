#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
const int xdirec[] = { -1, 0, 1, 0 };
const int ydirec[] = { 0, -1, 0, 1 };
int main()
{
	// ABC088-D, 997, 
	int h, w;
	cin >> h >> w;
	string s;
	vector<vector<int>> mp(h, vector<int>(w, -2));
	rep(i, h) {
		cin >> s;
		rep(j, w) {
			if (s[j] == '.') mp[i][j] = -1;
		}
	}

	mp[0][0] = 0;
	queue<P> que;
	que.push(P(0, 0));
	while (!que.empty()) {
		P v = que.front();
		que.pop();
		rep(i, 4) {
			int x = v.first + xdirec[i];
			int y = v.second + ydirec[i];
			if (x < 0 || w <= x || y < 0 || h <= y) continue;
			if (mp[y][x] != -1) continue;
			mp[y][x] = mp[v.second][v.first] + 1;
			que.push(P(x, y));
		}
	}

	if (mp[h - 1][w - 1] == -1) {
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	ans = h*w - mp[h - 1][w - 1] - 1;
	rep(i, h) rep(j, w) {
		if (mp[i][j] == -2) ans--;
	}
	cout << ans << endl;
	return 0;
}