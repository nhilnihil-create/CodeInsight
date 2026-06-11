#include<bits/stdc++.h>
using namespace std;
#define long long long int
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();
const int mod = 1e9 + 7;
long dp[3001][3001];

void add( long &a, long b ) {
      a += b;
      while ( a > mod ) a -= mod;
      while ( a < 0 ) a += mod;
}

int main () { _read(); 

      int n; string s;
      cin >> n >> s;
      dp[1][1] = 1;
      for( int i = 2; i <= n; i++) {
            for( int j = 1; j < i; j++) {
                  add(dp[i-1][j],dp[i-1][j-1]);
            }
            for( int j = 1; j <= i; j++) {
                  int L,R;
                  if(s[i-2] == '<') {
                        L = 1, R = j-1;
                  }
                  else {
                        L = j; R = i-1;
                  }
                  add(dp[i][j],dp[i-1][R]-dp[i-1][L-1]);
            }
      }
      long ans = 0;
      for( int i = 1; i <= n; ++i) {
            add(ans,dp[n][i]);
      }
      cout << ans << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
