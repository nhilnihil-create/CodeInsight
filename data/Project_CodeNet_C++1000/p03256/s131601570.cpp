#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,m;
  string s;
  cin >> n >> m >> s;
  s="#"+s;
  mat v(n+1);
  mat deg(n+1,vec(2));
  vec q,vis(n+1);
  for(ll i=m,x,y;i--;) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    deg[x][s[y]-'A']++;
    deg[y][s[x]-'A']++;
  }
  for(ll i=1;i<=n;i++) {
    if(!deg[i][0]||!deg[i][1]) {
      q.push_back(i);
      vis[i]=1;
    }
  }
  for(ll i=0;i<q.size();i++) {
    for(auto j:v[q[i]]) {
      if(!--deg[j][s[q[i]]-'A']&&!vis[j]) {
        q.push_back(j);
        vis[j]=1;
      }
    }
  }
  cout << (q.size()<n?"Yes":"No") << endl;
}