#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

bool compare(const pint p1, const pint p2) { return p1.second > p2.second; }

int main() {
  int n;
  cin >> n;
  vector<pint> red(n), blue(n);
  rep(i, 0, n) cin >> red[i].first >> red[i].second;
  rep(i, 0, n) cin >> blue[i].first >> blue[i].second;

  // blue は最小の x が必要なので昇順
  sort(blue.begin(), blue.end());
  // red は最大の y が必要なので降順
  sort(red.begin(), red.end(), compare);

  int ans = 0;
  vector<bool> used(n);
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (used[j]) continue;
      if (blue[i].first > red[j].first && blue[i].second > red[j].second) {
        used[j] = true;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
