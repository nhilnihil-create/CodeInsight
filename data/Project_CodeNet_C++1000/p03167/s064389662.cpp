#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main(){
  int H,W; cin >> H >> W;
  vector<string> field(H);
  rep(i, H) cin >> field[i];
  vector<vector<int>> dp(H + 1,vector<int>(W + 1, 0));
  dp[0][0] = 1; 
  rep(i, H) {
    rep(j, W) {
      //     cout << i << " " << j << endl; 
      if(j + 1 < W) if(field[i][j + 1] == '.') {
	dp[i][j + 1] += dp[i][j];
	dp[i][j + 1] %= MOD;
      }
      if(i + 1 < H) if(field[i + 1][j] == '.') {
	  dp[i + 1][j] += dp[i][j];
	  dp[i + 1][j] %= MOD;
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}