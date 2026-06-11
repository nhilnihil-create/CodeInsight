#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Distance Sums

using P = pair<int64_t, int64_t>;

vector<int64_t> graph[100001];
bool visited[100001];
P dfs(int64_t v) {  // firstが和,secondがサイズ
  visited[v] = true;
  int64_t sum = 0;
  int64_t size = 1;
  for (const auto& e : graph[v]) {
    if (!visited[e]) {
      auto tmp = dfs(e);
      sum += tmp.first + tmp.second;
      size += tmp.second;
    }
  }
  return make_pair(sum, size);
}

int main() {
  int64_t N;
  cin >> N;
  map<int64_t, P> mp;
  int64_t check;
  for (int64_t i = 1; i <= N; i++) {
    int64_t x;
    cin >> x;
    mp[x] = make_pair(i, 1);  // 頂点番号と木のサイズ
    if (i == 1) check = x;
  }
  if (N == 2) {
    cout << -1 << endl;
    return 0;
  }
  vector<P> ans;
  auto enditr = mp.rend();
  enditr--;
  for (auto itr = mp.rbegin(); itr != enditr; ++itr) {
    auto key = itr->first;
    auto value = itr->second;
    auto vertex = value.first;
    auto size = value.second;
    auto child_key = (key + 2 * size) - N;
    if (child_key >= key) continue;
    auto tmpitr = mp.find(child_key);
    if (tmpitr != mp.end()) {
      auto tmp = tmpitr->second;
      mp.at(child_key) = make_pair(tmp.first, tmp.second + size);
      ans.push_back(make_pair(vertex, tmp.first));
      graph[vertex].push_back(tmp.first);
      graph[tmp.first].push_back(vertex);
    }
  }
  if (ans.size() == N - 1) {
    // これが本当に条件を満たしているか確かめればおそらくACがくる．←模範解答はそうだった．
    // ただ，「不可能なのに可能と言ってしまっている」原因はわからない．
    // 理由はおそらく，相対値しか見ていないから．
    // 一頂点について計算してみる．
    fill(visited, visited + 100001, false);
    auto L = dfs(1);
    // cout << L.first << ' ' << check << endl;
    if (L.first == check) {
      for (const auto& e : ans) {
        cout << e.first << ' ' << e.second << endl;
      }
    } else {
      cout << -1 << endl;
    }

  } else {
    cout << -1 << endl;
  }
  return 0;
}
