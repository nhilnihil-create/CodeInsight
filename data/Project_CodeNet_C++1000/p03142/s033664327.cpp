#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  int n, m;
  cin >> n >> m;

  vi es[101010];
  vi h(101010, 0);
  REP(i, n + m - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    es[a].push_back(b);
    h[b]++;
  }

  int root = 0;
  REP(i, n) if (h[i] == 0)  {
    root = i;
  }

  queue<int> que;
  que.push(root);
  vi pre(n, -1);
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (int v: es[u]) {
      h[v]--;
      if (h[v] == 0) {
        pre[v] = u;
        que.push(v);
      }
    }
  }

  // cout << root << endl;

  REP(i, n) {
    cout << pre[i] + 1 << endl;
  }

  return 0;
}
