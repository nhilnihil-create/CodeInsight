//e4-e5-f4
//#include <boost/multiprecision/cpp_int.hpp> 
#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"
//#include "ext/pb_ds/tree_policy.hpp"
typedef long long int ll;
typedef double db;
// __int128 s128;
// __uint128_t u128;
typedef unsigned long long u64;
#define int long long int
#define PI 3.14159265359
#define sz(a) (ll)a.size()
#define lt(a) (ll)a.length()
#define pll pair<ll,ll>
#define tc(x) ll x; cin>>x; while(x--)
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define bac(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define print(a)  for (auto x : a) cout << x << " "; cout << endl
#define sl set<ll>
#define usl unordered_set<ll>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define vl vector<ll>
#define vpl vector<pll>
#define vvl vector<vector<ll>>
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define setbits(a) __builtin_popcountll(a)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define F first
#define S second
#define teevra_gati ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define P 1000000007
#define Q 1000000006
#define inf 1e18
#define N 100005
#define M 105
//using namespace boost::multiprecision; 
//using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(all(v), rng);
vl adj[N];
ll vis[N], b[N], w[N];
void dfs(ll s){
    ll black=1,white=1;
    for(auto u:adj[s]){
        if(!vis[u]){
            vis[u]=1;
            dfs(u);
            (black *= w[u]) %= P;
            (white *= (w[u]+b[u])%P ) %= P;
        }
    }
    b[s] = black;
    w[s] = white;
}
void solve(){
    ll n;
    cin>>n;
    f(i,1,n){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vis[1]=1;
    dfs(1);
    cout<<(b[1]+w[1])%P;
}

signed main() {
    teevra_gati
        
    solve();

    return 0;
}