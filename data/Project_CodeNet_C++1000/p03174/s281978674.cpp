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

int bit_num(int bit) {
  int num = 0;
  while(bit > 0) {
    if(bit % 2 == 1) {
      num++;
    }
    bit /= 2;
  }
  return num;
} 

int main() {
  int N; cin >> N;
  vector<vector<int>> a(N, vector<int>(N,0));
  rep(i, N)rep(j, N) cin >> a[i][j];
  vector<ll> dp(1 << (N + 1), 0);
  dp[0] = 1;
  rep(i, 1 << N) {
    rep(j, N) {
      //      cout << i << " " << j << endl;
      if(((i >> j) & 1) == 0) continue;
      int pre = i - (1 << j);
      dp[i] = (dp[i] + dp[pre] * a[bit_num(i) - 1][j]) % MOD;
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}