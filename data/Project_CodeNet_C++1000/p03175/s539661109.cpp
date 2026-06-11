#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ )
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ones(x) (ll) __builtin_popcount(x)
#define fs first
#define sc second
#define pb push_back
#define po pop_back
#define mp make_pair  
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tsie(nullptr);cout.tie(nullptr)
#define watch(x) cout << (#x) << " is #" << (x) <<"#" <<endl
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
const ll mod = 1e9+7;
const ll MAX = 1e5+34;
const ll inf = 1e18+7;
vi adj[MAX];
ll dp[MAX][3];

void dfs(ll u, ll parent){
  dp[u][0] = dp[u][1] = 1;
  for(auto v: adj[u]){
    if(v == parent) continue;
    dfs(v,u);
    dp[u][0] = (dp[u][0]*dp[v][1])%mod;
    dp[u][1] = (dp[u][1]*(dp[v][0]+dp[v][1])%mod)%mod;
  }
}

int main(){
  fastio;
  ll n,x,y;
  cin>>n;
  f(i,0,n-1){
    cin>>x>>y;
    x--;y--;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs(0,0);
  cout<<(dp[0][0]+dp[0][1])%mod<<"\n";
  return 0; 
}