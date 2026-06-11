#include <bits/stdc++.h>

using namespace std;

int main() {
  int L;
  cin >> L;
  int sink = 0;
  vector< pair< pair<int, int>, int> > edge;
  for (int i = 1; i < 20; i++) {
    if (L > (1 << i) - 1) {
      sink = i;
      edge.emplace_back(make_pair(i - 1, i), 0);
      edge.emplace_back(make_pair(i - 1, i), 1 << (i - 1));
    }
  }

  int w = L;
  for (int i = 0; i < sink; i++) {
    if (1 << i & L) {
      w -= 1 << i;
      edge.emplace_back(make_pair(i, sink), w);
    }
  }

  cout << sink + 1 << " " << edge.size() << "\n";
  for (auto e : edge) {
    cout << e.first.first + 1 << " ";
    cout << e.first.second + 1 << " ";
    cout << e.second << "\n";
  }
  return 0;
}