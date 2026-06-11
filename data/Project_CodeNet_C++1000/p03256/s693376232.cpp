#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

bool topologicalSort(const vec<int, 2>& G, vector<int>& order) {
  const int V = G.size();
  vector<int> deg(V, 0);
  for (int v = 0; v < V; v++) {
    for (int u : G[v]) {
      ++deg[u];
    }
  }
  queue<int> pq;
  for (int v = 0; v < V; v++) {
    if (deg[v] == 0) {
      pq.push(v);
    }
  }
  order.clear();
  while (!pq.empty()) {
    int v = pq.front();
    pq.pop();
    order.push_back(v);
    for (int u : G[v]) {
      --deg[u];
      if (deg[u] == 0) {
        pq.push(u);
      }
    }
  }
  return order.size() == V;
}

int main() {
  int N, M;
  while (cin >> N >> M) {
    string S;
    cin >> S;
    vec<int, 2> G(N);
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    vec<int, 2> dG(2 * N);
    for (int a = 0; a < N; a++) {
      for (int b : G[a]) {
        if (S[a] == S[b]) {
          dG[2 * a + 0].push_back(2 * b + 1);
        } else {
          dG[2 * a + 1].push_back(2 * b + 0);
        }
      }
    }
    vector<int> order;
    bool res = !topologicalSort(dG, order);
    cout << (res ? "Yes" : "No") << endl;
  }
  return 0;
}
