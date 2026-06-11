#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
const int MAXN = 2e5+10;
vector<int> adj[MAXN];

pair<int,int> dfs(int u, int p=-1) {
  //cerr << u << " " << p <<endl;
  pair<int, int> ans = {0,u};
  for(int v:adj[u]) {
    if (v==p) continue;
    ans = max(dfs(v, u), ans);
  }
  ans.first++;
  return ans;
}

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto v = dfs(1);
  auto rv = dfs(v.second);
  int dia = rv.first;
  //cerr << dia <<endl;
  if (dia>1 && dia%3==2) cout << "Second" <<endl;
  else cout << "First" <<endl;
}
