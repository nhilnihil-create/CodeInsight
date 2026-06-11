#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> to;
vector<vector<int>> cost;

vector<int> color;
vector<int> x = {1, 0};

void dfs(int v, int c) {
  color[v] = c;
  for (int i = 0; i < to[v].size(); i++) {
    if (color[to[v][i]] != -1) continue;
    if (cost[v][i] % 2 == 0) dfs(to[v][i], c);
    else dfs(to[v][i], x[c]); 
  }
}

void solve() {
  int n;
  cin >> n;
  to.resize(n);
  cost.resize(n);
  color.resize(n, -1);
  rep(i,n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);
  }

  dfs(0, 1);

  rep(i,n) cout << color[i] << endl;
  
}

int main() {
  solve();
  return 0;
}