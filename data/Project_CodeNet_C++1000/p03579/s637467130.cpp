#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using Graph = vector<vector<ll>>;
vector<int> color;
bool dfs(const Graph &g, ll v, int cur = 0) {
  color[v] = cur;
  for(auto nv: g[v]){
    if(color[nv]!=-1){
      if(color[nv]==color[v]) return false;
      continue;
    }
    if(!dfs(g,nv,1-cur)) return false;
  }
  return true;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, M;
  cin >> N>> M;
  color.assign(N,-1);
  Graph g(N);
  for(ll i = 0LL; i< M; i++) {
    ll x, y;
    cin >> x >> y;
    g.at(x-1LL).push_back(y-1LL);
    g.at(y-1LL).push_back(x-1LL);
  }
  ll cnt=0LL;
  if(!dfs(g,0LL)) cnt = (N*(N-1LL))/2LL;
  else {
    ll t=0LL;
    ll s = 0LL;
    for(auto i: color) {
      if(i==0) t++;
      if(i==1) s++;
    }
    cnt = s*t;
  }
  cout<<cnt-M<<endl;
}
      