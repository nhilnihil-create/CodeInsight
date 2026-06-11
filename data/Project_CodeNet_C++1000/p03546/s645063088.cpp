#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<int> d(10, INF);
vector<edge> g[10];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    REP(i,g[v].size()) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  IOS;
  int h, w; cin >> h >> w;
  REP(i,10) {
    REP(j,10) {
      int cost; cin >> cost;
      g[i].push_back({ j, cost });
    }
  }

  int memo[10];
  REP(i,10) {
    dijkstra(i);
    memo[i] = d[1];
  }

  int ans = 0;
  REP(i,h) REP(j,w) {
    int a; cin >> a;
    if (a == -1) continue;
    ans += memo[a];
  }

  COUT(ans);
  return 0;
}