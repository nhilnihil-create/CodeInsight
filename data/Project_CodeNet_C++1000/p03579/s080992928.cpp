#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int n_max=1e5+5;
vector<int> g[n_max];
int color[n_max];
bool ok=true;

void dfs(int v, int col){
  if(color[v]==-1){
    color[v]=col;
    for(auto i : g[v]){
      dfs(i, (col+1)%2);
    }
  }
  else if(color[v]!=col){
    ok=false;    
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,m;
  cin >> n >> m;
  int a,b;
  rep(i,m){
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  rep(i,n) color[i]=-1;
  dfs(0,0);
  if(ok){
    ll ta,tb;
    ta=tb=0;
    rep(i,n){
      if(color[i]) ta++;
      else tb++;
    }
    cout <<ta*tb-m << endl;
  }
  else cout << n*(n-1)/2-m << endl;
  
  return 0;
    

}
