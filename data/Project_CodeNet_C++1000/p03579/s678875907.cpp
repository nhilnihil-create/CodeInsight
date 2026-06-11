//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{
  ll to,cost;
};
ll color[100010];
vector<vector<ll> >G(100010);
bool dfs(ll v,ll c){
  color[v]=c;
  rep(i,G[v].size()){
    if(color[G[v][i]]==c)return false;
    if(color[G[v][i]]==0&&!dfs(G[v][i],-c))return false;
  }
  return true;
}
    
int main(){
  ll n,m;cin>>n>>m;
  rep(i,m){
    ll a,b;cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,n){
    if(color[i]==0){
      if(!dfs(i,1)){
        cout<<n*(n-1)/2-m<<endl;
        return 0;
      }
    }
  }
  ll plus=0,minus=0;
  rep(i,n){
    if(color[i]==1)plus++;
    else minus++;
  }
  cout<<plus*minus-m<<endl;
}
  
  
  