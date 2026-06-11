#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
#define ffs fflush(stdout);
#define int ll
#define sz(x) (ll)x.size()
using namespace std;
 
 
const ll MOD = 998244353 ;
const ll INF = 1e9;
const ll LOG = 29;
#define PI 3.141592653589793238 
 
 
long long binpow(long long a, long long b) {
     a%=MOD;    
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
 
        
        b >>= 1;
    }
     res%=MOD;
    return res;
}
 
const ll N =(1e5+5);
const ld ep = 1e-9;
vll adj[N];
bool vis[N];
void dfs(ll u){
    vis[u] = true;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void solve(){
    ll n,m;
    cin >> n >> m;
    for(int i =1;i<=m;i++){
        ll u,v,z;
        cin >> u >> v >> z;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;

}


 
   
 
 
 
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
       
 
    ll tt=1;
    while(tt--){
        solve();
    }    
}