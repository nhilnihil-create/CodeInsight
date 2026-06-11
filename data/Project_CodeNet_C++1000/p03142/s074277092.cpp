#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i > n; --i)
typedef long long ll;
#define mod 1000000007

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N + 1);
  vector<int> deg(N + 1);
  rep(i, 0, N + M - 1) {
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    deg[B]++;
  }
  queue<int> Q;
  rep(i, 1, N + 1) if(!deg[i]) Q.push(i);
  vector<int> par(N + 1);
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(auto p : G[cur]) {
      deg[p]--;
      par[p] = cur;
      if(!deg[p]) Q.push(p);
    }
  }
  rep(i, 1, N + 1) cout << par[i] << "\n";
  return 0;
}
