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

ll rec(int n, vector<vector<int>> &tree, vector<vector<ll>> &dp, int black, int par) {
  if(dp[n][black] != -1) return dp[n][black];
  if(tree[n].size() == 0) return dp[n][black] = 1;
  ll res = 1;
  if(black) {
    for (auto child : tree[n]) {
      if(child != par) {
	res = (res * rec(child, tree, dp, 0, n)) % MOD;
      }
    } 
  } else {
    for(auto child : tree[n]) {
      if(child != par) {
	res = (res * (rec(child, tree, dp, 0, n) + rec(child, tree, dp, 1, n)) % MOD) % MOD;
      }
    }
  }
  return dp[n][black] = res;
}


int main() {
  int N; cin >> N;
  vector<vector<int>> tree(N, vector<int>());
  rep(i, N - 1) {
    int x, y; cin >> x >> y;
    x--; y--;
    tree[x].push_back(y);
    tree[y].push_back(x);    
  }
  vector<vector<ll>> dp(N, vector<ll>(2, -1));
  ll ans = (rec(0, tree, dp, 0, -1) + rec(0, tree, dp, 1, -1)) % MOD;
  cout << ans << endl;
}