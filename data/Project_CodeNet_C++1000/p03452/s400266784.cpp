#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

vector<pair<ll,ll>> v[mx];
vector<bool> used(mx,false);
vector<ll> d(mx,0);

void dfs(int x){
  rep(i,v[x].size()){
    if(!used[v[x][i].F]){
      used[v[x][i].F] = true;
      d[v[x][i].F] = d[x]+v[x][i].S;
      dfs(v[x][i].F);
    }
  }
}


int main(){
  int n,m; cin >> n >> m;
  vector<int> l(m),r(m),dis(m);
  rep(i,m){
    cin >> l[i] >> r[i] >> dis[i];
    v[l[i]].emplace_back(pair<ll,ll>(r[i],dis[i]));
    v[r[i]].emplace_back(pair<ll,ll>(l[i],-dis[i]));
  }
  rep(i,n){
    if(!used[i+1]){ used[i+1]=true; dfs(i+1);}
  }
  
  bool ans=true;
  rep(i,m){
    if(d[r[i]]-d[l[i]]!=dis[i]){ ans=false; }
  }

  if(ans){ cout << "Yes" << endl; } else { cout << "No" << endl; }
  return 0;
}