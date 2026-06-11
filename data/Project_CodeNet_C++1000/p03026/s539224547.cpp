#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 1e4 + 5;

vector < vector < ll > > adj(MAXN, vector < ll > ());
vector < ll > val(MAXN), v;

ll ans = 0;
void dfs(ll u, ll p){
  val[u] = v.back();
  v.pop_back();
  for(auto to : adj[u]){
    if(to != p){
      dfs(to, u);
      ans += min(val[to], val[u]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > deg(n + 1, 0);
  set < ll > score;
  for(int i = 0; i < n - 1; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for(int i = 0; i < n; i++){
    ll a; cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());

  dfs(n, -1);

  cout << ans << '\n';
  for(int i = 1; i <= n; i++) cout << val[i] << " ";
  cout << '\n';
}
