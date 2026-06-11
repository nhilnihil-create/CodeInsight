#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
const long long MAX_V = 1010101;

struct edge {
  long long to, cost;
};

long long V;
vector<edge> Graph[MAX_V];
long long dist[MAX_V];

void dijkstra(long long s) {
  priority_queue<Pll, vector<Pll>, greater<Pll>> que;

  // 0-indexed
  fill(dist, dist + V, INF);
  // 1-indexed
  // fill(dist + 1, dist + 1 + V, INF);

  dist[s] = 0;
  que.push(Pll(0, s));

  while (!que.empty()) {
    auto elem = que.top();
    que.pop();

    auto cv = elem.second;

    if (elem.first > dist[cv]) {
      continue;
    }

    for (auto e : Graph[cv]) {
      if (dist[e.to] > dist[cv] + e.cost) {
        dist[e.to] = dist[cv] + e.cost;
        que.push(Pll(dist[e.to], e.to));
      }
    }
  }
}

int H, W;
int A[300][300];

int main() {
  cin >> H >> W;
  repe(i, 0, 9) {
    repe(j, 0, 9) {
      int c;
      cin >> c;
      Graph[j].push_back(edge{i, c});
    }
  }

  V = 10;
  dijkstra(1);
  int ans = 0;
  rep(i, 0, H) {
    rep(j, 0, W) {
      int a;
      cin >> a;
      if (a != -1) {
        ans += dist[a];
      }
    }
  }
  cout << ans << endl;
}
