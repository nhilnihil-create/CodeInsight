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
  int N; cin >> N;
  vector<double> p(N);
  rep(i, N) cin >> p[i];
  vector<vector<double>> dp(N + 1, vector<double>(N + 1,0));
  dp[0][0] = 1;
  rep(i, N) {
    rep(j, i + 1) {
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
      dp[i + 1][j + 1] += dp[i][j] * p[i];
    }
  }
  double ans = 0;
  for (int i = (N / 2) + 1; i <= N; i++) {
    ans += dp[N][i];
  }
  cout << fixed << setprecision(10) << ans << endl; 
}