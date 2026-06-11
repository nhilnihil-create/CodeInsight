#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define FOR(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using ll = long long;

int k;
vector<int> d;

int bfs() {
  deque<int> Q;
  REP(i,k) d[i] = INF;
  d[1] = 1;
  Q.push_back(1);
  while (Q.size()) {
    auto v = Q.front(); Q.pop_front();
    int nv = (v+1)%k;
    if (d[nv] == INF) {
      d[nv] = d[v] + 1; Q.push_back(nv);
    }
    nv = (v*10)%k;
    if (d[nv] > d[v]) {
      d[nv] = d[v]; Q.push_front(nv);
    }
  }
  return d[0];
}

int main() {
  cin >> k;
  d.resize(k);
  int ans = bfs();
  cout << ans << endl;
  return 0;
}
