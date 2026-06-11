#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, int> P;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define Rep(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int H, W;
using Grid = vector<vector<char>>;
Grid grid;
vector<vector<int>> dist;
queue<P> Q;

//vector<int> d_number(2510, 0);

int white_number = 0;

int max_d = 0;

int main() {
	cin >> H >> W;
	grid.resize(H, vector<char>(W));
	rep(i, H) rep(j, W) {
		cin >> grid[i][j];
		if (grid[i][j] == '.') white_number++;
	}

	dist.assign(H, vector<int>(W, -1));
	dist[0][0] = 0;
	Q.push(make_pair(0, 0));
	//d_number[0]++;

	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		rep(i, 4) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			else if (dist[nx][ny] != -1 || grid[nx][ny] == '#') continue;
			else {
				dist[nx][ny] = dist[x][y] + 1;
				Q.push(make_pair(nx, ny));
				//d_number[d]++;
			}
		}
	}

	if (dist[H - 1][W - 1] == -1) cout << -1 << endl;
	else cout << white_number - dist[H-1][W-1] - 1 << endl;
}	