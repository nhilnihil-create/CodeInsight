#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<int, int, int>> V;
  for (int i = 0; i < N; i++) {
    int x, y, h;
    cin >> x >> y >> h;
    if (h == 0) continue;
    V.push_back(make_tuple(x, y, h));
  }
  if (V.size() == 1) {
    return cout << get<0>(V.at(0)) << " " << get<1>(V.at(0)) << " " << get<2>(V.at(0)) << "\n", 0;
  }
  for (int x = 0; x <= 100; x++) {
    for (int y = 0; y <= 100; y++) {
      int diff = -1, h;
      for (auto v : V) {
        int tmp = 2e9 - abs(get<0>(v) - x) - abs(get<1>(v) - y) - get<2>(v);
        if (diff == -1) diff = tmp;
        if (tmp != diff) goto NG;
      }
      h = get<2>(V.at(0)) + abs(get<0>(V.at(0)) - x) + abs(get<1>(V.at(0)) - y);
      cout << x << " " << y << " " << h << "\n";
      NG:;
    }
  }
}