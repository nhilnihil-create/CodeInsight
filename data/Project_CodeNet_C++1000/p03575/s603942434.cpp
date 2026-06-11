#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  pb     push_back
#define  all(x) (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  deb(x) cout << #x << " - " << x << "\n";
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)  { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  ps(x,y) fixed<<setprecision(y)<<x
 
#define PI 3.141592653589793
const ll MOD = 1e9 + 7;
const ll INF = 10000000000;
const ll MAX_N = 1e6 + 2;

vi adj[100],vis(100,0),in(100),low(100);
int cnt = 0,timer = 0;

void dfs(int node,int par){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    
    for(auto child: adj[node]){
        if(child==par) continue;
        
        if(vis[child]==1){
            low[node] = min(low[node] , in[child]);
        } else{
            dfs(child,node);
            if(low[child] > in[node]) cnt++;
            low[node] = min(low[node] , low[child]);
        }
    }
}

void solve(){
    int n,a,b,e; cin >> n >> e;
    while(e--){
        cin >> a >> b;
        adj[a].pb(b) , adj[b].pb(a);
    }
    dfs(1,-1);
    cout << cnt;
}
 
int main() {
    IOS;
    int t; t=1;
    // int t; cin >> t;
    while(t--) solve();
}