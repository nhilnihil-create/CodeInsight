#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const int inf=1e5+10;

int n,m,ind;
vector<vector<int>> g(100010),g2(100010);
vector<bool> used(100010,false);
vector<int> v,v2(100010),v3(100010),ans(100010);

void dfs(int now){
  if(used[now]) return;
  used[now]=true;
  for(auto itr:g[now]) dfs(itr);
  v.push_back(now);
  v2[now]=ind;
  v3[ind--]=now;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ind=n;
    rep(i,n+m-1){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g2[b].push_back(a);
    }
    FOR(i,1,n+1) if(!used[i]) dfs(i);
    FOR(i,1,n+1){
      int cnt=0;
      for(auto itr:g2[i]){
        cnt=max(cnt,v2[itr]);
      }
      ans[i]=v3[cnt];
    }
    FOR(i,1,n+1) cout<<ans[i]<<endl;
}