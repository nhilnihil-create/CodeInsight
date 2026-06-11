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

vector<vector<ll>> dp;

ll rec(int l, int r, vector<ll> &sum) {
  if(dp[l][r] != -1) return dp[l][r];
  ll res = INF;
  rep(i, r - l) {
    chmin(res,rec(l, l + i, sum) + rec(l + i + 1, r, sum));
  }
  return dp[l][r] = res + sum[r + 1] - sum[l];
}

int main() {
  int N; cin >> N;
  vector<ll> a(N), sum(N + 1, 0);
  rep(i, N) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  dp = vector<vector<ll>>(N, vector<ll>(N, -1));
  rep(i, N) dp[i][i] = 0;
  ll ans = rec(0, N - 1, sum);
  cout << ans << endl;
}