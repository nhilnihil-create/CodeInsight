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

int main() {
  int N, K; cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  vector<ll> pre(K + 10, 0), now(K + 10,0);
  pre[0] = 1;
  rep(i, N) {
    now[0] = pre[0];
    rep(j, K + 1) {
      if(j == 0) continue;
      now[j] = (pre[j] + now[j - 1]) % MOD;
    }
    pre = now;
    rep(j, K + 1) {
      if(j - a[i] - 1 >= 0) {
	now[j] = (pre[j] - pre[j - a[i] - 1] + MOD) % MOD; 
      }
    }
    pre = now;
  }
  cout << now[K] << endl;
}