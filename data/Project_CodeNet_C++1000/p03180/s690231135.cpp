#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
template<class T>using vv = vector<vector<T>>;

#define in(v) v; cin >> v;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define repi(i,a,b) for(int i=(a),_i=(b);i<_i;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int N;
vv<int> A;
ll dp[1<<16][16];
const ll INF = 1e15;
ll dfs(int used, int i) {
  if (i == N) return 0;
  if (dp[used][i] != INF) return dp[used][i];
  if (used & (1 << i)) return dfs(used, i+1);

  ll ans = 0;
  int notUsed = ((1 << N)-1) ^ used;
  for (int bit = notUsed; bit > 0; bit = (bit-1)&notUsed) {
    ll tmp = 0;
    bool ok = true;
    rep(j, N) {
      if (j == i && !(bit & (1 << i))) {
        ok = false; break;
      }
      if (bit & (1 << j))
        rep(k, j+1, N) {
          if (bit & (1 << k))
            tmp += A[j][k];
        }
    }
    if (ok)
      ans = max(ans, tmp + dfs(used | bit, i+1));
  }

  return dp[used][i] = ans;
}
int main() {
  in(N);
  A.resize(N, vector<int>(N, 0));

  rep(i, 1<<16) rep(j, 16) dp[i][j] = INF;
  rep(i, N) rep(j, N) {
    cin >> A[i][j];
  }
  cout << dfs(0, 0) << endl;

  return 0;
}
