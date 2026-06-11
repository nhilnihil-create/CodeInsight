
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

int nNode, nEdge;

struct E {
  int a, b;
  ll c;
};

E es[200000+10];
vector<E> g[100000+10];

ll dist[100000+10];
bool visited[100000+10];

int main(void) {
  int nNode, nEdge;
  scanf("%d%d", &nNode, &nEdge);
  REP(iEdge, nEdge) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    --l;
    --r;
    es[iEdge].a = r;
    es[iEdge].b = l;
    es[iEdge].c = -d;
    g[r].push_back(es[iEdge]);
    es[iEdge].a = l;
    es[iEdge].b = r;
    es[iEdge].c = d;
    g[l].push_back(es[iEdge]);
  }

  REP(s, nNode) {
    if(visited[s]) {
      continue;
    }
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      REP(i, g[u].size()) {
        const E& e = g[u][i];
        int v = e.b;
        if(!visited[v]) {
          q.push(v);
          dist[v] = dist[u] + e.c;
          visited[v] = true;
        }
      }
    }
  }
  bool ok = true;
  REP(iEdge, nEdge) {
    if(dist[es[iEdge].a] + es[iEdge].c != dist[es[iEdge].b]) {
      ok = false;
      break;
    }
  }
  puts(ok ? "Yes" : "No");
  
  return 0;
}
