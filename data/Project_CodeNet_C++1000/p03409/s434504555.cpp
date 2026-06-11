#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int ao[203][203];

int main() {
  int n, a, b, ans = 0;
  cin >> n;
  rep(i, n) cin >> a >> b, ao[b][a] = 1;

  vector<pair<int, int>> p(n);
  rep(i, n) cin >> p[i].second >> p[i].first;
  sort(p.begin(), p.end());

  rep(i, n) {
    int x = -1, y = -1;
    rep(j, p[i].second) {
      rep(k, p[i].first) {
        if (ao[k][j]) x = j, y = k;
      }
    }
    if (x != -1) ao[y][x] = 0, ans++;
  }

  cout << ans << endl;
  return 0;
}
