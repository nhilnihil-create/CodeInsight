#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1000000;

typedef pair<int, int> P;

int h, w;
char field[55][55];
int d[55][55];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int y, int x){
	queue<P> que;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			d[i][j] = INF;
		}
	}
	que.push(P(x, y));
	d[y][x] = 0;
	while(que.size()){
		P p = que.front(); que.pop();
		for(int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
			if(field[ny][nx] == '#') continue;
			if(d[ny][nx] != INF) continue;
			que.push(P(nx, ny));
			d[ny][nx] = d[p.second][p.first] + 1;
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> h >> w;
	int white = 0;
	rep(i,h)rep(j,w){
		cin >> field[i][j];
		if(field[i][j] == '.') ++white;
	}
	bfs(0, 0);
	if(d[h-1][w-1] == INF) cout << -1 << endl;
	else cout << white - d[h-1][w-1] - 1 << endl;
	return 0;
}
