#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

vl G[50];
vl B;
vP p;

void dfs(ll x,ll j){
  ll k=G[x].size();
  B[x]=1;
  rep(i,k){
    if((x==p[j].first&&G[x][i]==p[j].second)||(G[x][i]==p[j].first&&x==p[j].second)){
      continue;
    }
    if(B[G[x][i]]==0){
      dfs(G[x][i],j);
    }
  }
}

int main() {
  ll n,m;
  cin >> n >> m;
  ll ans=0;
  p.resize(m);
  rep(i,m){
    cin >> p[i].first >> p[i].second;
    p[i].first--;
    p[i].second--;
    G[p[i].first].push_back(p[i].second);
    G[p[i].second].push_back(p[i].first);
  }
  rep(i,m){
    B.assign(n,0);
    dfs(0,i);
    rep(i,n){
      if(B[i]==0){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}