#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 1e5 + 5;

vector < vector < ll > > adj(MAXN, vector < ll > ());
vector < bool > used(MAXN, false);
vector < ll > v;

void dfs(ll u){
  used[u] = true;
  for(auto to : adj[u]){
    if(!used[to]){
      dfs(to);
    }
  }
  v.push_back(u);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  for(int i = 0; i < n + m - 1; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for(int i = 1; i <= n; i++){
    if(!used[i]){
      dfs(i);
    }
  }
  reverse(v.begin(), v.end());

  vector < ll > ans(n + 1, 0);
  for(int i = n - 1; i >= 0; i--){
    for(auto to : adj[v[i]]){
      if(ans[to] == 0){
        ans[to] = v[i];
      }
    }
  }

  for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}
