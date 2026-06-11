#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e6 + 5;

vector<int> adj[N];
int n, sub[N];
ll d[N], D;
map<ll, int> pos;

void no_answer() {
  puts("-1");
  exit(0);
}

void calc(int u, int p, int d = 0) {
  D += d; 
  for (int v : adj[u]) calc(v, u, d + 1);
}

void check(int u, int p, ll D) {
  if (D != d[u]) no_answer();
  for (int v : adj[u]) check(v, u, D + n - 2 * sub[v]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
    pos[d[i]] = i;
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 1);
  sort(ord.begin(), ord.end(), [](int i, int j) { return d[i] > d[j]; });

  for (int i = 0; i < n - 1; ++i) {
    int u = ord[i];
    ++sub[u];
    ll dp = d[u] - n + 2 * sub[u];
    if (!pos.count(dp)) no_answer();
    int p = pos[dp];
    sub[p] += sub[u];
    adj[p].push_back(u);
  }

  calc(ord[n - 1], 0);
  check(ord[n - 1], 0, D);

  for(int i = 1; i <= n; ++i) {
    for(int j : adj[i]) {
      printf("%d %d\n", i, j); 
    }
  }

  return 0;
}
