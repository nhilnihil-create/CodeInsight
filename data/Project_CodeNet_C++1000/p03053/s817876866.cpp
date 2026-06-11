#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

char a[1005][1005];
int dist[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	int h,w;
	cin >> h >> w;
	rep(i,h) rep(j,w) cin >> a[i][j];
	queue<pair<int,int>> que;
	rep(i,h) rep(j,w) {
		dist[i][j] = -1;
		if(a[i][j] == '#'){
			que.push(make_pair(i,j));
			dist[i][j] = 0;
		}
	}
	while(!que.empty()){
		auto p = que.front(); que.pop();
		rep(i,4){
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w || dist[ny][nx] != -1) continue;
			if(a[ny][nx] == '.'){
				que.push(make_pair(ny, nx));
				dist[ny][nx] = dist[p.first][p.second] + 1;
			}
		}
	}
	int ans = 0;
	rep(i,h)rep(j,w) ans = max(ans, dist[i][j]);
	cout << ans << endl;
	return 0;
}

