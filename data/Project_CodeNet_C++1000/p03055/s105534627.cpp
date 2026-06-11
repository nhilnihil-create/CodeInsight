#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2e5 + 5;

vector < vector < int > > adj(N);

pair < int, int > dfs (int s) {
  vector < int > d(N, INT_MAX);
  d[s] = 0;
  queue < int > q;
  vector < bool > used(N, false);
  used[s] = true;
  q.push(s);
  int mx = s, mx_dis = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto to : adj[u]) {
      if (!used[to]) {
        d[to] = d[u] + 1;
        if (d[to] > mx_dis) {
          mx_dis = d[to];
          mx = to;
        }
        used[to] = true;
        q.push(to);
      }
    }
  }
  return {mx, mx_dis};
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int u = dfs(1).first;
  pair < int, int > p = dfs(u);
  int v = p.first, diameter = p.second;

  if (diameter % 3 == 1) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
}
