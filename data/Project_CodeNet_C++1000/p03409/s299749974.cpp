#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int N, x, y, ans{};
  cin >> N;
  using pii = pair<int,int>;
  auto f = [](const pii &p1, const pii &p2){return p1.second > p2.second;};
  set<pii, decltype(f)> r(f);
  set<pii> b;
  for (int i = 0; i != N; ++i) {
    cin >> x >> y;
    r.insert({x,y});
  }
  for (int i = 0; i != N; ++i) {
    cin >> x >> y;
    b.insert({x,y});
  }

  for (auto &p: b) {
    for (auto &q: r) {
      if (q.first < p.first && q.second < p.second) {
        r.erase(q);
        ++ans;
        break;
      }
    }
  }
  cout << ans << endl;
}
