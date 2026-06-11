#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 5;

vector < vector < int > > adj (N);
vector < int > side (N, -1);
int cnt0 = 0, cnt1 = 0;

bool check_bipartite () {
  side[1] = 0;
  queue < int > q;
  q.push (1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto to : adj[u]) {
      if (side[to] == -1) {
        side[to] = side[u] ^ 1;
        q.push (to);
      } else if (side[u] == side[to]) {
        return false;
      }
    }
  }

  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back (v);
    adj[v].push_back (u);
  }

  if (check_bipartite ()) {
    for (int i = 1; i <= n; i++) {
      if (side[i]) cnt1++;
      else cnt0++;
    }
    ll ans = (ll)cnt0 * cnt1;
    cout << max ((ll)0, ans - m) << '\n';
  } else {
    ll ans = ((ll)n * (n - 1)) / 2;
    cout << max ((ll)0, ans - m) << '\n';
  }
}
