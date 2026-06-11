#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> dp(100001);
vector<bool> ok(100001);
vector<vector<int> > g(100001);

int solve(int x) {
	if(ok[x]) return dp[x];
	ok[x] = true;
	int rec = 0;
	rep(y, g[x].size()){
		chmax(rec, solve(g[x][y]) + 1);
	}
	return dp[x] = rec;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
	}

	int ans = 0;
	rep(i, n){
		chmax(ans, solve(i));
	}
	cout << ans << endl;
}