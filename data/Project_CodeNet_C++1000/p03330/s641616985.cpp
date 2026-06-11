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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n, c;
	cin >> n >> c;
	int grid[n][n];
	int d[c][c];
	rep(i,c)rep(j,c){
		cin >> d[i][j];
	}
	rep(i,n)rep(j,n){
		cin >> grid[i][j];
		grid[i][j]--;
	}
	int color[3][c];
	rep(i,3)rep(j,c) color[i][j]=0;
	rep(i,n)rep(j,n){
		color[(i+j)%3][grid[i][j]]++;
	}
	ll ans = INF;
	vector<vector<pair<ll,int>>> v(3); 
	rep(i,3){
		rep(j,c){
			ll now = 0;
			rep(k,c){
				now += color[i][k]*d[k][j];
			}
			pair<ll, int> e = make_pair(now, j);
			v[i].push_back(e);
		}
	}
	rep(i,3) sort(v[i].begin(), v[i].end());
	rep(i,3)rep(j,3)rep(k,3){
		if(v[0][i].second==v[1][j].second||v[1][j].second==v[2][k].second||v[2][k].second==v[0][i].second) continue;
		chmin(ans, v[0][i].first+v[1][j].first+v[2][k].first);
	}
	cout << ans << endl;

}