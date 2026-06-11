#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; typedef long long ll;
const int MAXN = 10 + 1e5;
const ll oo = 1 + 1e18, mod = 7 + 1e9;

int n, a[MAXN][5], f[MAXN][5];

int main(){
  #define TASK "ABC"
  #ifndef ONLINE_JUDGE
  freopen(TASK".inp","r",stdin),freopen(TASK".out","w",stdout);
  #endif ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++) cin >> a[i][j];

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= 3; j++){
      for (int k = 1; k <= 3; k++){
        if (j != k) f[i][j] = max (f[i][j], f[i - 1][k] + a[i][j]);
      }
    }
  }

  int ans = 0; for (int i = 1; i <= 3; i++) ans = max (ans, f[n][i]);
  cout << ans;

  return 0;
}
