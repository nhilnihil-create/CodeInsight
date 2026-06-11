#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

struct edge {
  ll from, to, cost;
  edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

typedef pair<long long, int> P; // firstは最短距離、secondは頂点の番号
vector<edge> es[100001];

int main() {

  ll K;
  cin >> K;

  REP(i, K) {
    int to = (i + 1) % K;
    es[i].emplace_back(edge(i, to, 1));
  }

  REP(i, K) {
    int to = (i * 10) % K;
    es[i].emplace_back(edge(i, to, 0));
  }

  vll d(K, (1 << 30));
  d[1] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, 1));

  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();

    if (d[p.second] < p.first)
      continue;

    for (auto e : es[p.second]) {
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        pq.push(P(d[e.to], e.to));
      }
    }
  }

  cout << d[0] + 1 << endl;

  return 0;
}
