#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int color [MAX_N];
set<int> adj [MAX_N][2];

int in_to_del [MAX_N];
vector<int> to_del;

int check (int u) {
  return adj[u][0].empty() || adj[u][1].empty();
}

void del (int u) {
  vector<int> nbs;
  for (int v : adj[u][0]) nbs.push_back(v);
  for (int v : adj[u][1]) nbs.push_back(v);

  adj[u][0].clear();
  adj[u][1].clear();

  for (int v : nbs) {
    adj[v][color[u]].erase(u);
  }

  for (int v : nbs) {
    if (!in_to_del[v] && check(v)) {
      in_to_del[v] = 1;
      to_del.push_back(v);
    }
  }
}

int main () {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      color[i + 1] = 0;
    } else {
      color[i + 1] = 1;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u][color[v]].insert(v);
    adj[v][color[u]].insert(u);
  }

  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      in_to_del[i] = 1;
      to_del.push_back(i);
    }
  }

  int delc = 0;
  while (!to_del.empty()) {
    int u = to_del.back();
    to_del.pop_back();
    delc++;
    del(u);
  }

  if (delc == n) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
