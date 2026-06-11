#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
using ll = long long;
vector<int> c;

bool dfs(const Graph &G, int v, int cr=0) {
  c.at(v) = cr;
  for(auto nv : G[v]) {
    if(c.at(nv) != -1) {
      if(c.at(nv) == cr)
        return 0;
      continue;
    }

    if(!dfs(G, nv, 1-cr))
      return 0;
  }
  return 1;
}

int main() {
  int N,M,i,A,B;
  ll c1=0, c2=0;
  bool isBipartite = 1;
  cin >> N >> M;
  Graph G(N);

  for(i=0; i<M; i++) {
    cin >> A >> B;
    A--; B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  c.assign(N, -1);
  for(i=0; i<N; i++) {
    if(c.at(i) != -1)
      continue;
    if(!dfs(G, i))
      isBipartite = 0;
  }

  if(isBipartite) {
    for(i=0; i<N; i++)
      if(c.at(i) == 0)
        c1++;
      else
        c2++;
    cout << c1*c2-M;
  } else
    cout << (ll)N*(N-1)/2-M;
  cout << endl;
}