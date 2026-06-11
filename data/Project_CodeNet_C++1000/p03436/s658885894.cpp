#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> l;
	rep(i, h) {
		string rc;
		cin >> rc;
		l.push_back(rc);
	}

	vector<vector<int>> dist(h, vector<int>(w, -1));
	dist[0][0] = 0;
	queue<pair<int,int>> q;
	q.push(pair<int,int>(0, 0));

	auto Add = [&](int y, int x, int d) {
		if (y < 0 || y >= l.size()) return;
		if (x < 0 || x >= l[y].size()) return;
		char m = l[y][x];
		if (m != '.') return;
		if (dist[y][x] == -1) {
			dist[y][x] = d;
		}
		else{
			if (dist[y][x] <= d)
			{
				return;
			}
			else
			{
				dist[y][x] = d;
			}
		}
		q.push(pair<int, int>(y, x));

	};

	while (!q.empty())
	{
		pair<int,int> now = q.front(); q.pop();
		int d = dist[now.first][now.second];
		Add(now.first - 1, now.second, d + 1);
		Add(now.first + 1, now.second, d + 1);
		Add(now.first, now.second - 1, d + 1);
		Add(now.first, now.second + 1, d + 1);
	}
	int count = dist[h - 1][w - 1] + 1;
	int ans = 0;
	rep(i, h) {
		rep(j, w) {
			if (l[i][j] == '.') {
				ans++;
			}
		}
	}
	ans -= count;
	if (count == 0) {
		ans = -1;
	}
	cout << ans << endl;

	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}