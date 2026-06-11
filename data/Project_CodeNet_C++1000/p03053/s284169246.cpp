#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm> // min()
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <tuple>
#include <climits> // INT_MAX
#include <cmath> // ceil()
#define rep(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;



int main() {
	int h, w, black_num = 0, times = 0;
	cin >> h >> w;

	auto max_black = h * w;

	vector<string> mp(h);
	queue<P> q;
	rep(i, h) {
		cin >> mp[i];
		rep(j, w) {
			if (mp[i][j] == '#') {
				q.emplace(j, i);
				++black_num;
			}
		}
	}

	if (max_black == black_num) {
		cout << 0 << endl;
		return 0;
	}

	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };
	queue<P> p;

	int x, y, x_next, y_next;
	while (true) {
		while (!q.empty()) {

			x = q.front().first;
			y = q.front().second;
			q.pop();

			rep(i, 4) {
				x_next = x + dx[i];
				y_next = y + dy[i];
				if (x_next < 0 || x_next >= w) continue;
				if (y_next < 0 || y_next >= h) continue;
				if (mp[y_next][x_next] == '#') continue;

				p.emplace(x_next, y_next);
				mp[y_next][x_next] = '#';
				++black_num;
			}
		}
		q.swap(p);
		++times;
		if (black_num == max_black) break;
	}

	cout << times << endl;
	return 0;
}
