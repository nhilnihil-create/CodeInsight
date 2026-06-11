#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vab(m);
  for (auto &p : vab) {
    cin >> p.first >> p.second;
  }

  sort(vab.begin(), vab.end());

  int r = vab[0].second, ans = 1;
  for (auto &p : vab) {
    r = min(r, p.second);
    if (r - p.first < 1) {
      ans++;
      r = p.second;
    }
  }

  cout << ans << '\n';
  return 0;
}
