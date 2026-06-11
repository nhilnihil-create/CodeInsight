#include <bits/stdc++.h>
#define maxn 233
using namespace std;
char G[maxn][maxn];
int d[maxn][maxn];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int main() {
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", G[i] + 1);
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) 
			if(G[i][j] == '.') ++ans;
	queue<int> Qx, Qy;
	memset(d, -1, sizeof d);
	d[1][1] = 0;
	Qx.push(1), Qy.push(1);
	while(!Qx.empty() && !Qy.empty()) {
		int x = Qx.front(), y = Qy.front();
		Qx.pop(), Qy.pop();
		for(int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if(nx && nx <= n && ny && ny <= m && d[nx][ny] == -1 && G[nx][ny] == '.') d[nx][ny] = d[x][y] + 1, Qx.push(nx), Qy.push(ny);
		}
	} 
	printf("%d\n", d[n][m] == -1 ? -1 : ans - d[n][m] - 1);
	return 0;
}