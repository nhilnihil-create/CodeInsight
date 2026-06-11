#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

int main() {
  int n;
  cin >> n;
  int data[105][15];
  ll profit[105][15];
  REP(i, n) {
    REP(j, 10) { cin >> data[i][j]; }
  }
  REP(i, n) {
    REP(j, 11) { cin >> profit[i][j]; }
  }
  ll ans = -LLONG_MAX;
  for (int bit = 0; bit < (1 << 11); ++bit) {
    int cnt[105] = {};
    for (int i = 0; i < 11; ++i) {
      if (bit & (1 << i)) {
        // 列挙にi番目の要素が含まれる場合の処理
        REP(k, n) {
          if (data[k][i] == 1) cnt[k]++;
        }
      }
    }
    bool flag = true;
    REP(k, n) {
      if (cnt[k] != 0) flag = false;
    }
    if (flag) continue;

    ll tmp = 0;
    REP(t, n) { tmp += profit[t][cnt[t]]; }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}