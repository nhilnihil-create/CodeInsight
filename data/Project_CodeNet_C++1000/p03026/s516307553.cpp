#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll n;
vector<ll>c;
vector<ll>to[10005];
vector<ll>ans;
ll x=0;
void dfs(ll v, ll p = -1){
 ans[v]=c[x];
 x++;
 for(ll i=0; i<to[v].size(); i++){
   ll u = to[v][i];
   if(u==p) continue;
   dfs(u,v);
 }
}

int main(){
  cin >> n;
  for(int i=0; i<n-1; i++){
    ll a,b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  
  ll res = 0;
  c.resize(n);
  for(int i=0; i<n; i++){
    cin >> c[i];
    res+=c[i];
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  res-=c[0];
  
  ans.resize(n);
  
  dfs(0);
  cout << res << endl;
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  
  return 0;
  
}
  
  
  
  
