#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main() {
  int n;
  cin >> n;
  set < pair < int, int > > gay, shit;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    pair < int, int > gang;
    cin >> gang.first >> gang.second;
    gay.insert(gang);
  }
  for (int i = 0; i < n; ++i) {
    pair < int, int > gang;
    cin >> gang.first >> gang.second;
    shit.insert(gang);
  }
  while (!shit.empty()) {
    auto pr = *shit.begin();
    shit.erase(shit.begin());
    pair < int, int > res = make_pair(-1, -1);
    for (auto gang: gay) {
      if (pr.x > gang.x && pr.y > gang.y)
        res = max(res, make_pair(gang.y, gang.x));
    }
    gay.erase(make_pair(res.y, res.x));
    if (res.first > -1)
      ++ans;
  }
  cout << ans << '\n';
}
