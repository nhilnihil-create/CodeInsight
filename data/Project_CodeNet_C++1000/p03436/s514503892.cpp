#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
int dp[55][55];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	int white = 0;
	rep(i,h){
		cin >> s[i];
		rep(j,w){
			if(s[i][j] == '.') ++white;
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	queue<P> que;
	que.push(P(0, 0));
	while(!que.empty()){
		P cur = que.front();
		que.pop();
		rep(i,4){
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if(ny < 0 || h <= ny) continue;
			if(nx < 0 || w <= nx) continue;
			if(s[ny][nx] == '#') continue;
			if(dp[ny][nx] <= dp[cur.first][cur.second]+1) continue;
			dp[ny][nx] = dp[cur.first][cur.second] + 1;
			que.push(P(ny, nx));
		}
	}
	if(dp[h-1][w-1] == INF){
		cout << -1 << endl;
		return 0;
	}
	int ans = white - dp[h-1][w-1] - 1;
	chmax(ans, 0);
	cout << ans << endl;
	return 0;
}