#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7, maxm = 1e6 + 7;
int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, vis[maxn][maxn];
char r[maxn];

struct Node{
	int x, y;
}node[maxm];
int s = 1, t = 0;

void bfs() {
	int x, y, X, Y;
	while(s <= t) {
		x = node[s].x; y = node[s].y;
		++s;
		for (int i = 0; i < 4; ++i) {
			X = x + D[i][0];
			Y = y + D[i][1];
			if(~vis[X][Y]) continue;
			vis[X][Y] = vis[x][y] + 1;
			node[++t].x = X; node[t].y = Y;
		}
	}
	printf("%d\n", vis[x][y]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) vis[i][j] = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", r + 1);
		for (int j = 1; j <= m; ++j) if(r[j] == '#') {
			node[++t].x = i; node[t].y = j;
			vis[i][j] = 0;
		}
	}
	bfs();
	return 0;
}