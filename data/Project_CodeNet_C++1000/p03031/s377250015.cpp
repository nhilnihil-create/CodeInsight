#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// 記事を見ないとビット全探索が書けない…
int main() {
  int n, m;
  cin >> n >> m;

  vector<int> K(m);
  vector<vector<int> > S(m, vector<int>(10));
  rep(i, m) {
    int k;
    cin >> k;
    K[i] = k;
    rep(j, k) {
      int s;
      cin >> s;
      s--;
      S[i][j] = s;
    }
  }

  vector<int> P(m);
  for (int i = 0; i < m; i++) cin >> P[i];

  int ans = 0;
  // スイッチの付け方をビット全探索
  for (int bits = 0; bits < (1 << n); bits++) {
    bool ok = true;

    // 電球を全探索
    for (int i = 0; i < m; i++) {
      int tmp_sum = 0;
      for(int j = 0; j < K[i]; j++) {
        // int mask = bits >> S[i][j];
        // if (mask & 1) {  // i番目のbitが立っていれば加算する
         if (bits & (1 << S[i][j])) {
          tmp_sum++;
        }
      }
      if (tmp_sum % 2 != P[i]) ok = false;
    }
    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}
