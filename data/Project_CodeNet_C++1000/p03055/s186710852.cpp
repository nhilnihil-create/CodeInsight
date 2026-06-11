#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;
constexpr int kMaxN = 3e5;
vector<int> graph[kMaxN];
std::array<bool, kMaxN> used;

void Dfs(int v, int& best_v, int& best_dist, int cur_dist) {
  used[v] = true;
  if (best_dist < cur_dist) {
    best_dist = cur_dist;
    best_v = v;
  }
  for (const auto& to : graph[v]) {
    if (!used[to]) {
      Dfs(to, best_v, best_dist, cur_dist + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  if (n == 1) {
    cout << "First" << endl;
    return 0;
  }
  
  for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
  }
  int best_v = 0;
  int best_dist = 0;
  Dfs(0, best_v, best_dist, 0);
  best_dist = 0;
  int best_v2 = 0;
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  Dfs(best_v, best_v2, best_dist, 0);
  cout << ((best_dist % 3 == 1) ? "Second" : "First") << endl;
}