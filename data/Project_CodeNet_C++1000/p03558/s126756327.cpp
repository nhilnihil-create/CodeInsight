#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  vector<pair<int, int> > adj[k];

  int dist1, dist2, weight;
  for (int i = 0; i < k; i++) {
    dist1 = (i * 10) % k;
    weight = 0;
    if ( dist1 != i ) {
      adj[i].push_back(make_pair(dist1, weight));
    }
    dist2 = (i + 1) % k;
    weight = 1;
    if ( dist2 != dist1 && dist2 != i) {
      adj[i].push_back(make_pair(dist2, weight));
    }
  }

  int *d;
  bool *visit;
  d = new int[k];
  visit = new bool[k];
  int next_u;
  for (int i = 0; i < k; i++) d[i] = 1000000;
  for (int i = 0; i < k; i++) visit[i] = false;
  d[1] = 1;
  deque <int> q;
  for (int i = 0; i < adj[1].size(); i++) {
    next_u = adj[1][i].first;
    if (adj[1][i].second == 0) {
      q.push_front(next_u);
      d[next_u] = d[1];
    } else {
      q.push_back(next_u);
      d[next_u] = d[1] + 1;
    }
  }

  int u;
  while ( !q.empty() ) {
    u = q.front(); 
    q.pop_front();
    for (int i = 0; i < adj[u].size(); i++) {
      next_u = adj[u][i].first;
      if (adj[u][i].second == 0 && !visit[next_u]) {
        q.push_front(next_u);
        d[next_u] = d[u];
      } else if (!visit[next_u]) {
        q.push_back(next_u);
        d[next_u] = d[u] + 1;
      }
    }
    visit[u] = true;
    if (u == 0) break;
  }

  cout << d[0] << endl;

  delete[] d;
  delete[] visit;

  return 0;

}