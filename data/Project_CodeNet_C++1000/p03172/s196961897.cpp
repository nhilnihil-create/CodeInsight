#include<bits/stdc++.h>
using namespace std;
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();
const int mod = 1e9 + 7;
int dp[101][100001];
int pre[101][100001];
int main () { _read(); 

      int n,m;
      cin >> n >> m;
      vector<int> v(n+1);
      for( int i = 1; i <= n; ++i) {
            cin >> v[i];
      }
      dp[0][0] = 1;
      for( int i = 1; i <= n; i++) {
            for( int k = 1; k <= m; k++) {
                  (dp[i-1][k] += dp[i-1][k-1]) %= mod;
            }
            for( int k = 0; k <= m; k++) {
                  dp[i][k] = (dp[i-1][k] - ( (k - v[i] - 1) >= 0 ? dp[i-1][k-v[i]-1] : 0) + mod ) % mod;
            }
      }
      cout << dp[n][m] << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
