#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  //input
  int N, T;
  cin >> N >> T;
  /*
  vector <int> c(N);
  vector <int> t(N);
  rep(i,N) cin >> c[i] >> t[i];
  */

  //solve
  //int MAX = 1 << 30;  //2の30乗
  int ans = inf;  //コスト

  rep(i,N){
    int c, t;
    cin >> c >> t;
    if (t <= T) ans = min(ans, c);
  }
  if (ans < inf) cout << ans << endl;
  else cout << "TLE" << endl;
}
