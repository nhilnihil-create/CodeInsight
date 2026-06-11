#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  int white_cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '.') white_cnt++;
    }
  }
  debug(white_cnt);
  vector<vector<int>> g(H * W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '#') continue;
      if (i != 0) {  // ue
        if (s[i - 1][j] == '.') g[i * W + j].push_back((i - 1) * W + j);
      }
      if (j != 0) {  // hidari
        if (s[i][j - 1] == '.') g[i * W + j].push_back(i * W + j - 1);
      }
      if (i != H - 1) {  // sita
        if (s[i + 1][j] == '.') g[i * W + j].push_back((i + 1) * W + j);
      }
      if (j != W - 1) {  // migi
        if (s[i][j + 1] == '.') g[i * W + j].push_back(i * W + j + 1);
      }
    }
  }
  debug(g);
  vector<int> visit_status(H * W), distance(H * W, -1);

  auto bfs = [&](int start_node) {
    distance[start_node] = 0;
    visit_status[start_node] = 1;
    queue<int> q;
    q.push(start_node);
    while (!q.empty()) {
      int node_id = q.front();
      q.pop();
      for (auto next_node_id : g[node_id]) {
        if (visit_status[next_node_id] != 0) continue;
        q.push(next_node_id);
        visit_status[next_node_id] = 1;
        distance[next_node_id] = distance[node_id] + 1;
      }
    }
  };

  bfs(0);
  debug(distance);
  if (distance.back() == -1) {
    cout << -1 << endl;
    return 0;
  }
  cout << white_cnt - distance.back() - 1 << endl;
  return 0;
}