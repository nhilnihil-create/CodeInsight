#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  vector<vector<int>> cost(n);
  rep(i,n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }

  vector<int> ans(n, -1);
  queue<int> q;
  ans[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int i = 0; i < tree[u].size(); i++) {
      int v = tree[u][i];
      if (ans[v] != -1) continue;
      else {
        if (cost[u][i] % 2 == 0) ans[v] = ans[u];
        else ans[v] = (ans[u] + 1) % 2;
        q.push(v);
      }
    }
  }
  rep(i,n) cout << ans[i] << endl;
}

int main() {
  solve();
  return 0;
}