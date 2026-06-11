#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using pint = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pint> p(m);
  rep(i, m) cin >> p[i].second >> p[i].first;
  sort(p.begin(), p.end());

  int ans = 1;
  int t = p[0].first;
  rep(i, m) {
    if (t <= p[i].second) {
      ans++;
      t = p[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
