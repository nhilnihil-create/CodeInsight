#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int n;
  cin >> n;
  vector<vector<Pll>> g(n);
  vll dis(n);
  rep(i,n-1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(Pll(v,w));
    g[v].push_back(Pll(u,w));
  }
  rep(i,n) dis[i] = -1;
  dis[0] = 0LL;
  queue<ll> q;
  q.push(0LL);
  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    for(auto e : g[v]) {
      if(dis[e.first]!=-1) continue;
      dis[e.first] = dis[v] + e.second;
      q.push(e.first);
    }
  }
  rep(i,n) {
    if(dis[i]%2==0) cout << 0 << endl;
    else cout << 1 << endl;
  }
  // rep(i,n) cout << dis[i] << endl;
  return 0;
}