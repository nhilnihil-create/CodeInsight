#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

int main() {
  ll N, M;
  cin >> N >> M;

  vi L(M), R(M), D(M);
  for (ll i = 0; i < M; i++) {
    cin >> L[i] >> R[i] >> D[i];
    L[i] -= 1;
    R[i] -= 1;
  }

  vector<vector<pii>> G(N);
  for (ll i = 0; i < M; i++) {
    G[L[i]].push_back(make_pair(R[i], D[i]));
    G[R[i]].push_back(make_pair(L[i], -D[i]));
  }

  vi x(N);
  unordered_set<ll> visited;

  for (ll i = 0; i < N; i++) {
    if (visited.find(i) == visited.end()) {
      x[i] = 0;
      queue<ll> q;
      q.push(i);
      visited.insert(0);
      while (q.size()) {
        ll fr = q.front();
        q.pop();
        for (pii j: G[fr]) {
          ll to = j.first;
          ll d = j.second;
          if (visited.find(to) == visited.end()) {
            x[to] = x[fr] + d;
            visited.insert(to);
            q.push(to);
          } else {
            if (x[to] != x[fr] + d) {
              cout << "No" << endl;
              return 0;
            }
          }
        }
      }
    }
  }

  cout << "Yes" << endl;
}