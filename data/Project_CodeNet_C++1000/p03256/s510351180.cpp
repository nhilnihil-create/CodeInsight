#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5+10;
const string s = "AABBAABB";

vector<int> adj[N];
string label;
int reach[N][4];

void go(int u, int k) {
  if(reach[u][k] == 1) {
    cout << "Yes" << endl;
    exit(0);
  }
  if(reach[u][k] == 2) return;
  reach[u][k] = 1;
  for(int v : adj[u])
    if(s[k+1] == label[v])
      go(v, (k+1)%4);
  reach[u][k] = 2;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  cin >> label;

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < n; i++)
    if(!reach[i][0])
      go(i, 0);

  cout << "No" << endl;
}

