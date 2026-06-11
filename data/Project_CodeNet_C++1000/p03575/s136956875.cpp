#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define  ff          first
#define  ss          second
#define  pb          push_back
#define  IOS         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  lb          lower_bound
#define  ub          upper_bound
#define  D2(x)       { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  all(x)      (x).begin(), (x).end()
#define  mem(a)      memset(a , 0 ,sizeof a)
#define  deb(x)      cout << #x << " - " << x << "\n";
#define  ps(x,y)     fixed<<setprecision(y)<<x
#define  setbit(x)   __builtin_popcount(x)
#define  deb2(x,y)   cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
 
#define PI 3.141592653589793
const ll p = 5;
const ll INF = 1000000000;
const ll MAX_N = 1e5 + 2;

vi adj[100],vis(100),in(100),pos_low(100);
map<int,int>bridges;
int timer,cnt;

void dfs(int node,int par){
    vis[node] = 1;
    in[node] = pos_low[node] = timer++; 
    
    for(auto child:adj[node]){
        if(child == par) continue;
        
        if(vis[child]){
            // Back edge
            pos_low[node] = min(pos_low[node] , in[child]);
        } else{
            // Forward edge
            dfs(child , node);
            
            if(in[node] < pos_low[child]) cnt++;
            
            pos_low[node] = min(pos_low[node] , pos_low[child]);
        }
    }
}

void solve(){
    int n,m; cin >> n >> m;
    int a,b;
    rep(i,0,m){
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1 , -1);
    cout << cnt;
}
 
int main() {
    IOS;
    // int t; cin >> t;
    int t=1; 
    while(t--) solve();
    return 0;
}