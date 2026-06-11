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

const ll MXN=100005;
vector<edge> G[MXN];
vl c(MXN,-1);

void bfs(ll x,ll k){
  c[x]=k;
  ll z=G[x].size();
  rep(i,z){
    if(c[G[x][i].to]==-1){
      bfs(G[x][i].to,(k+G[x][i].cost)%2);
    }
  }
}

int main() {
  ll N;
  cin >> N;
  rep(i,N-1){
    ll a,b,w;
    cin >> a >> b >> w;
    a--;
    b--;
    w%=2;
    G[a].push_back({b,w});
    G[b].push_back({a,w});
  }
  bfs(0,0);
  rep(i,N){
    cout << c[i] << endl;
  }
}