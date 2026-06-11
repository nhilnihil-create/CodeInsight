#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 5;

vector<int> adj [MAX_N];
int ans [MAX_N];
int arr [MAX_N];
int lvl [MAX_N];

void dfs (int u, int p) {
  lvl[u] = lvl[p] + 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int sum = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    mx = max(mx, arr[i]);
  }

  sort(arr, arr + n, greater<int>());

  dfs(1, 0);
  
  vector<pair<int, int>> ord;
  for (int i = 1; i <= n; i++) {
    ord.push_back(make_pair(lvl[i], i));
  }
  sort(ord.begin(), ord.end());

  for (int i = 0; i < n; i++) {
    ans[ord[i].second] = arr[i];
  }

  cout << sum - mx << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
