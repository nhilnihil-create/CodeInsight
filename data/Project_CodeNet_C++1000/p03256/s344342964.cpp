#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<vector<int> > Graph;

vector<int> tsort(Graph G, int start, int end) {
  vector<int> ret;

  int degree[end];
  memset(degree, 0, sizeof(degree));

  for (int from = start; from < end; from++) {
    for (int i = 0; i < G[from].size(); i++) {
      int to = G[from][i];
      degree[to]++;
    }
  }

  stack<int> root;

  for (int i = start; i < end; i++) {
    if (degree[i] == 0) {
      root.push(i);
    }
  }

  while (!root.empty()) {
    int from = root.top();
    root.pop();

    ret.push_back(from);

    for (int i = 0; i < G[from].size(); i++) {
      int to = G[from][i];
      degree[to]--;

      if (degree[to] == 0) {
        root.push(to);
      }
    }
  }

  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;

  string S;
  cin >> S;

  Graph G(N);

  int a, b;

  for (int i = 0; i < M; ++i) {
    cin >> a >> b;

    --a;
    --b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  Graph G2(2 * N);

  for (int v = 0; v < N; ++v) {
    int v2 = v + N;
    char c1 = S[v];

    for (int i = 0; i < G[v].size(); ++i) {
      int u = G[v][i];
      char c2 = S[u];
      int u2 = u + N;

      if (v == u) {
        G2[v].push_back(u2);
      } else {
        if (c1 == c2) {
          G2[v].push_back(u2);
          G2[u].push_back(v2);
        } else {
          G2[v2].push_back(u);
          G2[u2].push_back(v);
        }
      }
    }
  }

  vector<int> res = tsort(G2, 0, 2 * N);

  if (res.size() != 2 * N) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

