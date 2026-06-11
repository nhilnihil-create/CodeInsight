#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;

vector<int> to[100005];
vector<bool> d(100005);
vector<bool> visited(100005,0);
bool flag = 1;
void dfs(int v, int p=-1) {
  for (auto u : to[v]) {
    if(visited[u]){
      if(d[u]==d[v])flag=0;
      continue;
    }
    visited[u]=1;
    d[u] = 1-d[v];
    dfs(u,v);
  }
}

int main() {
  ll n,m;
  cin >> n >> m;
  rep(i,m) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  d[0]=0;
  //flag=1;
  visited[0]=1;
  dfs(0);
  if(flag){
    ll c0 =0,c1=0;
    rep(i,n){
      if(d[i]==0)c0++;
      else c1++;
    }
    ll ans = c0*c1-m;
    cout << ans << endl;
  }else{
    ll ans= n*(n-1)/2LL - m;
    cout << ans << endl;
  }
  return 0;
}
