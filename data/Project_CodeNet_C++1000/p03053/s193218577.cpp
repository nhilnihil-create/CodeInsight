#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	char grid[h][w];
	int dis[h][w];
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			dis[i][j] = INF;
		}
	}
	queue<P> Q;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> grid[i][j];
			if(grid[i][j]=='#') Q.push(P(i,j)), dis[i][j] = 0;
		}
	}
	while(!Q.empty()) {
		P p = Q.front();
		Q.pop();
		int x = p.first;
		int y = p.second;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0&&nx<h&&ny>=0&&ny<w&&grid[nx][ny]=='.'&&dis[nx][ny]==INF) {
				dis[nx][ny] = dis[x][y] + 1;
				Q.push(P(nx,ny));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			chmax(ans, dis[i][j]);
		}
	}
	cout << ans << endl;
}