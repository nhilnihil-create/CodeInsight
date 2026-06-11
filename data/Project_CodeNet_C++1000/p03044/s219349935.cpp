#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
    
   else{
       return(gcd(b, a%b));
    }
}
int main(){
  ll n;cin>>n;
  vector<vp> g(n);
  rep(i,0,n-1){
    ll u,v,w;cin>>u>>v>>w;
    u--;v--;
    g[u].push_back(make_pair(v,w%2));
    g[v].push_back(make_pair(u,w%2));
  }
  vll cost(n,-1);
  cost[0]=0;
  queue<ll> q;
  q.push(0);
  while(!q.empty()){
    ll tmp=q.front();
    q.pop();
    for(auto u:g[tmp]){
      if(cost[u.first]==-1){
        q.push(u.first);
        cost[u.first]=cost[tmp]+u.second;
        cost[u.first]%=2;
      }
    }
  }
  rep(i,0,n){
    cout<<cost[i]%2<<endl;
  }

}

