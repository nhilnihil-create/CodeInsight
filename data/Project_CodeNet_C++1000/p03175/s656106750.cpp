#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////

//#define int long long
#define endl '\n'
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+5;
vector<int> adj[N];
int branco[N], preto[N], root;

void dfs(int v, int p = -1){
  branco[v] = preto[v] = 1;
  for(int u : adj[v]) if(u != p){
    dfs(u, v);
    preto[v] = (preto[v]%MOD * branco[u]%MOD)%MOD;
    branco[v] = (branco[v]%MOD * (branco[u]%MOD + preto[u]%MOD)%MOD)%MOD;
  }
}

int32_t main(){
  fastio;
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  root = 1;
  dfs(root);
  if(n == 1) branco[root] = preto[root] = 1;
  cout << (branco[root]%MOD + preto[root]%MOD)%MOD << endl;
  return 0;
}