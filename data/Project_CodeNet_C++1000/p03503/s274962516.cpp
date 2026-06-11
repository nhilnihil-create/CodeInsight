#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  for( int i = 0; i < N; i++ ){
    for( int j = 0; j < 10; j++ ) cin >> F[i][j];
  }

  vector<vector<int>> P(N, vector<int>(11));
  for( int i = 0; i < N; i++ ){
    for( int j = 0; j < 11; j++ ) cin >> P[i][j];
  }

  int ans = -1000000000000000;
  for (int bit = 0; bit < (1<<10); ++bit) {
    vector<int> kaburi(N, 0);
    int now = 0;
    bool fg = 0;
    for (int i = 0; i < 10; ++i) {
      if (bit & (1<<i)) { // i番目のbitが立っていれば
      fg = 1;
        for( int j = 0; j < N; j++ ){
          if( F[j][i] == 1 ) kaburi[j]++;
        }
      }
    }
    for( int j = 0; j < N; j++ ){
      now += P[j][kaburi[j]];
    }
    if( fg ) ans = max(ans, now);
  }
  cout << ans << endl;




}
