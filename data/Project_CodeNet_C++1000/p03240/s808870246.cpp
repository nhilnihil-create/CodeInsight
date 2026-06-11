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
  int n;
  int a[105][4];
  cin >> n;
  REP(i, n) { cin >> a[i][0] >> a[i][1] >> a[i][2]; }
  ll cx, cy, ans_h, h;
  REP(i, 101) {
    REP(j, 101) {
      REP(k, n) {
        h = a[k][2] + abs(a[k][0] - i) + abs(a[k][1] - j);
        if (h < 1) continue;
        REP(s, n + 1) {
          if (s == n) {
            cx = i;
            cy = j;
            ans_h = h;
            break;
          }
          if (a[s][2] != max((ll)0, h - abs(a[s][0] - i) - abs(a[s][1] - j))) {
            break;
          }
        }
      }
    }
  }

  cout << cx << " " << cy << " " << ans_h << endl;
}