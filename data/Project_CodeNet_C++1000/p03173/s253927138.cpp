#include<bits/stdc++.h>
using namespace std;
#define long long long
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();
const long inf = 3e15 + 11;

int main () { _read(); 

      int n;
      cin >> n;
      vector<int> v(n+1);
      vector<long> p(n+1);
      vector<vector<long>> dp(n+1,vector<long>(n+1,inf));
      for( int i = 1; i <= n; ++i) {
            cin >> v[i];
            p[i] = p[i-1] + v[i];
            dp[i][i] = 0;
      }
      for( int len = 2; len <= n; ++len) {
            for( int i = 1, j = i + len - 1; j <= n; ++j, ++i) {
                  long x = p[j] - p[i-1];
                  for( int k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+x);
                  }
            }
      }
      cout << dp[1][n] << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
