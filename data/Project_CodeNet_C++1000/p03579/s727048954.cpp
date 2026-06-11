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
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

ll n,m;
vector<vector<ll>> g(100010); 
vector<ll> color(100010,0);

bool dfs(ll v,ll c){
  color[v]=c;
  for(auto itr:g[v]){
    if(color[itr]==c) return false;
    if(color[itr]==0 && !dfs(itr,-c)) return false;
  }
  return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,m){
      ll a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    if(dfs(1,1)){
      ll b=count(begin(color),end(color),1);
      ll w=count(begin(color),end(color),-1);
      cout<<b*w-m<<endl;
    }else{
      cout<<n*(n-1)/2-m<<endl;
    }
}