
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int h, w;
  cin >> h >> w;
  int a[505][505] = {};
  REP(i, h) {
    REP(j, w) { cin >> a[i][j]; }
  }
  vector<string> ans;
  REP(i, h) {
    REP(j, w) {
      if (a[i][j] % 2 == 1) {
        // 右下
        if (i == h - 1 && j == w - 1) break;
        // 一番右
        if (j == w - 1) {
          ans.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " +
                        to_string(i + 2) + " " + to_string(j + 1));
          // 移動元はもう見ないので無視
          a[i + 1][j]++;
        } else {
          ans.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " +
                        to_string(i + 1) + " " + to_string(j + 2));
          // 移動元はもう見ないので無視
          a[i][j + 1]++;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (auto s : ans) {
    cout << s << endl;
  }
}