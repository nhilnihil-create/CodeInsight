#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 1e9+7;
const int SQ =320;
const long double EPS = 1e-7;
vector<int> adj[200005];
pair<int,int> dfs(int node, int par){

  auto ret = ii(1,node);

  for(auto x : adj[node]){

    if(x != par){

      auto y = dfs(x,node);
      y.F++;
      ret=max(ret,y);

    }

  }

  return ret;
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int n;
  cin >> n;

  f(i,1,n){

    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);

  }

  int diameter = dfs(dfs(1,1).S,-1).F;
  
   if(diameter % 3 != 2)
    cout << "First\n";
  else
    cout << "Second\n";


  return 0;
}
