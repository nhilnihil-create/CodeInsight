#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vvi v;
vi d;
map<pii,int> m;

void dfs(int now,int par) {
  for(int x:v[now]) {
    if(x==par) continue;
    d[x]=d[now]+m.find(make_pair(now,x))->second;
    dfs(x,now);
  }
}

int main() {
  int N;
  cin >> N;
  vi w(N-1);
  v=vvi(N);
  rep(i,N-1) {
    int u,u2;
    cin >> u >> u2 >> w[i];
    v[u-1].push_back(u2-1);
    v[u2-1].push_back(u-1);
    m.insert(make_pair(make_pair(u-1,u2-1),w[i]));
    m.insert(make_pair(make_pair(u2-1,u-1),w[i]));
  }
  
  d=vi(N);
  dfs(0,-1);
  rep(i,N) {
    if(d[i]%2) cout << 1 << endl;
    else cout << 0 << endl;
  }
}