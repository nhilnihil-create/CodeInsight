#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
vector<ll>to[100005];
vector<ll>place[100005];
vector<ll>kyori(100005);

void dfs(ll v, ll p=-1){
  ll x = to[v].size();
  for(int i=0; i<x; i++){
    ll u=to[v][i];
    if(u==p) continue;
    if(kyori[u]) continue;
    kyori[u]=kyori[v]+place[v][i];
    dfs(u,v);
  }
}


int main(){
  ll n;
  cin >> n;
  for(int i=0; i<n-1; i++){
    ll u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    place[u].push_back(w);
    place[v].push_back(w);
    to[u].push_back(v);
    to[v].push_back(u);
  }
  kyori[0]=0;
  
  dfs(0);
  
  for(int i=0; i<n; i++){
    if(kyori[i]%2==0) cout << 0 << endl;
    else cout << 1 << endl;
  }
  
}
  
  
  
