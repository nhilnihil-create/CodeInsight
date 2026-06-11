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
vector<ll> dfs_d(mx,0);
vector<ll> l(mx),r(mx),d(mx);

void dfs(int x){
  for(auto to:v[x]){
    if(used[to.F]){ continue; }
    used[to.F] = true;
    dfs_d[to.F] = dfs_d[x] + to.S;
    dfs(to.F);
  }
}

int main(){  
  int n,m;
  cin >> n >> m;
  rep(i,m){
    cin >> l[i] >> r[i] >> d[i]; l[i]--; r[i]--;
    v[l[i]].emplace_back(pair<ll,ll>(r[i],d[i]));
    v[r[i]].emplace_back(pair<ll,ll>(l[i],-d[i]));
  }
  rep(i,n){ if(!used[i]){ used[i]=true; dfs(i); } }
  bool flag=true;
  rep(i,m){ if(d[i]!=dfs_d[r[i]]-dfs_d[l[i]]){flag=false; break;} }
  
  cout << (flag?"Yes":"No") << endl;
  return 0;
}