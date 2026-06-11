#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vll = vector<ll>;

void solve();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)

#define inl(...)  \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)

#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__);

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}

void out() {
  cout << endl;
}
template <typename T, class... U>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u))
    cout << " ";
  out(u...);
}

#define rep(i, n) for (long long i = 0; i < n; i++)

void solve();
#ifndef ONLINE_JUDGE
#include "./lib.hpp"
#endif

bool is_bridge(int N, vector<vector<bool>>& edges, int from, int to) {
    if (!edges[from][to]) return false;
    edges[from][to] = edges[to][from] = false;

    vector<bool> visited(N, false);
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        auto v = que.front(); que.pop();
        if (visited[v]) continue;
        visited[v] = true;

        rep(next, N) {
            if (edges[v][next])
                que.push(next);
        }
    }

    bool connected = true;
    rep(i, N) connected = connected && visited[i];

    edges[from][to] = edges[to][from] = true;
    return !connected;
}

void solve() {
    ini(N, M);
    vector<vector<bool>> edges(N, vector<bool>(N, false));
    rep(i, M) {
        ini(a, b);
        a--, b--;
        edges[a][b] = edges[b][a] = true;
    }

    ll ret = 0;
    rep(from, N) {
        for (ll to = from + 1; to < N; to++)
            if (is_bridge(N, edges, from, to)) {
                ret++;
            }
    }
    out(ret);
}
