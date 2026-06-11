#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,m;
  cin >> n >> m;
  int s[m][n+1];
  rep(i,m) {
    cin >> s[i][0];
    rep(j,s[i][0]) {
      cin >> s[i][j+1];
      s[i][j+1]--;
    }
  }

  int p[m];
  rep(i,m) cin >> p[i];

  int ans = 0;
  rep(i,1<<n) {
    bool flag = true;
    rep(j,m) {
      int cnt = 0;
      rep(k,s[j][0]) {
        if (i>>s[j][k+1]&1) cnt++;  // i番目のビットが1となっているか
      }
      if (cnt%2 != p[j]) flag = false;
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
