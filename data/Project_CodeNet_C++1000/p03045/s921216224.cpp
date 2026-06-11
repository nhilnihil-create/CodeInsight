#include <bits/stdc++.h>
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define td(v) v.begin(),v.end()
#define sz(v) (int)v.size()
//#define M   1000000007 // 1e9 + 7
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll mod(ll n, ll m ){ ll ret = n%m; if(ret < 0) ret += m; return ret; }
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
ll exp(ll a,ll b,ll m){
    if(b==0LL) return 1LL;
    if(b==1LL) return mod(a,m);
    ll k = mod(exp(a,b/2,m),m);
    if(b&1LL){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}


const int N = 100100;
int cor[N];
vector<pii> g[N];
int vis[N];
int cor0,cor1=0;
void dfs(int v){
  vis[v] = 1;
  for(auto e : g[v]){
    if(vis[e.ff])continue;
    cor[e.ff] = cor[v]^e.ss;
    dfs(e.ff);
  }
  if(cor[v]==0)cor0++;
  else cor1++;
}

int32_t main(){
 fastio;
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++){
   int x,y,z;
   cin>>x>>y>>z;
    // x + y == z mod2
   z%=2;
   if(z==0){
    g[x].pb(pii(y,0));
    g[y].pb(pii(x,0));
   }else{
    g[x].pb(pii(y,1));
    g[y].pb(pii(x,1));
   }
 }

 int res=0;
 for(int i=1;i<=n;i++){
  if(g[i].size()==0){
    res ++ ;
  }else if(!vis[i]){
    cor0 = cor1 = 0;
    cor[i] = 0;
    dfs(i);
    //res+=min(cor0,cor1);
    res ++;
  }
 }
 cout << res << endl;

  // Math -> gcd it all
  // Did u check N=1? Did you switch N,M?
}