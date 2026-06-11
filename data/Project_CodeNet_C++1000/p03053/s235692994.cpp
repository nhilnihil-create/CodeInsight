#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>
#include <list>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
vector<int> dx = { 1,0,-1,0 }, dy = { 0,1,0,-1 };

int main(void)
{
	int H, W; cin >> H >> W;
	vector<string> A(H); rep(i, 0, H)cin >> A[i];
	vector<vector<int>> dis(H, vector<int>(W, 0));
	queue<int> X, Y;
	rep(i, 0, H) {
		rep(j, 0, W) {
			if (A[i][j] == '#') {
				X.push(i);
				Y.push(j);
			}
		}
	}

	while (!X.empty()) {
		int x = X.front(); X.pop();
		int y = Y.front(); Y.pop();

		rep (i, 0, 4) {
			if (x + dx[i] < 0 || x + dx[i] >= H || y + dy[i] < 0 || y + dy[i] >= W)continue;
			if (A[x + dx[i]][y + dy[i]] == '.') {
				A[x + dx[i]][y + dy[i]] = '#';
				X.push(x + dx[i]);
				Y.push(y + dy[i]);
				dis[x + dx[i]][y + dy[i]] = dis[x][y] + 1;
			}
		}
	}
	int ans = -1;
	rep(i, 0, H)rep(j, 0, W)ans = more(ans, dis[i][j]);
	cout << ans << endl;

	return 0;
}
