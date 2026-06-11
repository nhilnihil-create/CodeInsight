#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, M, S[200000];
vector<ll> E[200000];
bool used[200000][2][2], visited[200000][2][2];

bool dfs(ll v, ll p1, ll p2) {
  if (visited[v][p1][p2]) return true;
  used[v][p1][p2] = true;
  visited[v][p1][p2] = true;
  for (ll u : E[v]) {
    if ((p2 == p1 && p1 != S[v] && S[v] == S[u]) || (p2 != p1 && p1 == S[v] && S[v] != S[u])) {
      if (dfs(u, S[v], p1)) return true;
    }
  }
  visited[v][p1][p2] = false;
  return false;
}

int main(void) {
  string s;
  cin >> N >> M >> s;
  REP(i, 0, N) S[i] = (s[i] == 'A' ? 0 : 1);
  REP(i, 0, M) {
    ll A, B;
    cin >> A >> B, A--, B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  REP(i, 0, N) REP(j, 0, 2) REP(k, 0, 2) {
    used[i][j][k] = false;
    visited[i][j][k] = false;
  }

  REP(p1, 0, 2) REP(p2, 0, 2) {
    REP(v, 0, N) if (!used[v][p1][p2]) {
      if ((p2 == p1 && p1 != S[v]) || (p2 != p1 && p1 == S[v])) {
        if (dfs(v, p1, p2)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}