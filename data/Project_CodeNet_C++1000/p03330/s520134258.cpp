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
	int d[c][c];
	int color[3][c];
	rep(i,3)rep(j,c) color[i][j]=0;
	rep(i,c)rep(j,c) cin >> d[i][j];
	rep(i,n)rep(j,n){
		int x;
		cin >> x;
		color[(i+j)%3][x-1]++;
	}
	ll ans = INF;
	rep(i,c)rep(j,c)if(i!=j)rep(k,c)if(i!=k&&j!=k) {
		ll tmp = 0;
		rep(l,c) tmp += color[0][l]*d[l][i];
		rep(l,c) tmp += color[1][l]*d[l][j];
		rep(l,c) tmp += color[2][l]*d[l][k];
		chmin(ans, tmp);
	}

	cout << ans << endl;
}