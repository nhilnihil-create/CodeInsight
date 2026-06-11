#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int H, W;
string S[1010];
int d[1010][1010];
int vx[] = { 0,1,0,-1 };
int vy[] = { 1,0,-1,0 };
struct point {
	int x, y;
};
queue<point> que;
void bfs() {
	while (!que.empty()) {
		point now = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + vx[i];
			int ny = now.y + vy[i];
			if (nx < 0 || nx >= W || ny < 0 || ny >= H ||
				d[ny][nx] != mod || S[ny][nx] == '#') continue;
			d[ny][nx] = d[now.y][now.x] + 1;
			que.push({ nx,ny });
		}
	}
}
int main()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> S[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				que.push({ j,i });
				d[i][j] = 0;
			}
			else d[i][j] = mod;
		}
	}
	bfs();
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << endl;
}