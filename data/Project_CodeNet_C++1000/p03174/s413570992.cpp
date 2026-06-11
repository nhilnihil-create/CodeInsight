#include<bits/stdc++.h>
using namespace std;
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();
const int mod = 1e9 + 7;
int dp[(1 << 21)];
bool ok[22][22];
int main () { _read(); 

      int n;
      cin >> n;
      for( int i = 0; i < n; ++i) {
            for( int j = 0; j < n; ++j) {
                  cin >> ok[i][j];
            }
      }
      dp[0] = 1;
      for( int mask = 0; mask < ( 1 << n ) - 1; mask++) {
            int man = __builtin_popcount(mask);
            for( int bit = 0; bit < n; bit++) {
                  if((mask >> bit) &1 ) continue;
                  if(!ok[man][bit]) continue;
                  (dp[mask|(1 << bit)] += dp[mask]) %= mod;
            }
      }
      cout << dp[(1 << n) - 1] << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
