#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char mp[55][55];
int dist[55][55];
int main() {
	int h, w;
	cin >> h >> w;
	int sharpcount = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '#') {
				sharpcount++;
			}
			dist[i][j] = inf;
		}
	}
	dist[0][0] = 0;
	queue<P>que;
	que.push(make_pair(0, 0));
	while (!que.empty()) {
		int nowx = que.front().second;
		int nowy = que.front().first;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = nowx + dx[i];
			int newy = nowy + dy[i];
			if (newx >= 0 && newx < w && newy >= 0 && newy < h && dist[newy][newx] == inf && mp[newy][newx] == '.') {
				dist[newy][newx] = dist[nowy][nowx] + 1;
				que.push(make_pair(newy, newx));
			}
		}
	}
	
	if (dist[h - 1][w - 1] != inf) {
		cout << h * w - (sharpcount + dist[h - 1][w - 1] + 1) << endl;
	}
	else {
		cout << "-1" << endl;
	}
	return 0;
}