#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(ll u, vector<ll> &graph, vector<vector<ll>> &side) {
  ll Gu = graph.at(u);
  for(ll i = 0; i < side.at(u).size(); i++) {
    ll v = side.at(u).at(i);
    if(graph.at(v) != -1) {
      if(graph.at(v) == Gu) return false;
      continue;
    }
    graph.at(v) = abs(graph.at(u) - 1);
    if(!dfs(v, graph, side)) return false;
  }
  return true;
}

int main() {
  ll N, M; cin >> N >> M;
  vector<vector<ll>> side(N, vector<ll> (0));
  vector<ll> graph(N, -1);
  for(ll i = 0; i < M; i++) {
    ll A, B; cin >> A >> B; A--; B--;
    side.at(A).push_back(B);
    side.at(B).push_back(A);
  }
  graph.at(0) = 0;
  bool judge = dfs(0, graph, side);
  ll w = 0, b = 0;
  for(ll i = 0; i < N; i++) {
    if(graph.at(i) == 0) w++;
    if(graph.at(i) == 1) b++;
  }
  if(judge) cout << 1LL *b * w - M << endl;
  else cout << 1LL * N * (N - 1) / 2 - M << endl;
}