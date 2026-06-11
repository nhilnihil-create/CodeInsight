#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, r, n) for (int i = (r); i <= (n); i++)

using ll = long long;
using namespace std;

ll white[100100], black[100100];
vector<int> G[100100];
const ll MOD = 1000000007;

pair<ll,ll> dfs(int v, int p = -1){
    ll white = 1;
    ll black = 1;
    for(auto nv : G[v]){
      if(nv == p) continue;
      pair<ll,ll> np = dfs(nv,v);
      white *= np.first + np.second;
      white %= MOD;
      black *= np.first;
      black %= MOD;      
    }
  return make_pair(white,black);
}

int main(){
    int n; cin >> n;
    rep(i,n-1){
        int x, y; cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
  pair<ll,ll> p = dfs(0);
  cout << (p.first+p.second) % MOD << endl;
  return 0;
}