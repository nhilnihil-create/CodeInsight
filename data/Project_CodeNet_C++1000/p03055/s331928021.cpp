#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

pair<int, int> farthest (int u, int p) {
  auto ans = make_pair(0, u);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      auto pr = farthest(nxt, u);
      pr.first++;
      ans = max(ans, pr);
    }
  }
  return ans;
}

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int r = farthest(1, 0).second;
  int diam = farthest(r, 0).first;
  diam++;

  if (diam % 3 == 2) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}
