/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;
struct Vertex {
  vector<int32_t> neighbours;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  bool is_okay = true;
  char last_word = 0;
  set<string> m;
  for (int32_t i = 0; i < N; ++i) {
    string w;
    cin >> w;
    if (i > 0 && w.c_str()[0] != last_word) {
      is_okay = false;
    }
    if (m.count(w) > 0) {
      is_okay = false;
    }
    m.insert(w);
    last_word = w.c_str()[w.length() - 1];
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
