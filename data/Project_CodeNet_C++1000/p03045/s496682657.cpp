//#define _GLIBCXX_DEBUG
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
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

vl G[100000];
vl visited(100000,0);

void bfs(ll s){
  queue<ll> que;
  que.push(s);
  visited[s]=1;
  while(!que.empty()){
    ll v=que.front();
    que.pop();
    ll x=G[v].size();
    rep(i,x){
      ll nv=G[v][i];
      if(visited[nv]==1){
        continue;
      }
      visited[nv]=1;
      que.push(nv);
    }
  }
}

int main() {
  ll n,m;
  cin >> n >> m;
  rep(i,m){
    ll x,y,z;
    cin >> x >> y >> z;
    x--;y--;
    G[x].pb(y);
    G[y].pb(x);
  }
  ll cnt=0;
  rep(i,n){
    if(visited[i]==0){
      bfs(i);
      cnt++;
    }
  }
  cout << cnt << endl;
}