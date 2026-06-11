#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define N               100005
#define ff              first
#define ss              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fio(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

vi gr[N];
ll dp[N][2];

ll dfs(ll cur, ll par, bool b){

    if(dp[cur][b] != -1) return dp[cur][b];

    ll ans = 0;
    ll a1 = 1, a2 = 1;
    
    // neigh can be painted white whether cur is black or white
    for(auto &neigh : gr[cur]){
        if(neigh != par) {
            a1 = (a1 * dfs(neigh, cur, false)) % mod;
        }
    }
    ans = (ans + a1) % mod;

    // if curr is not painted black => neigh can be painted black
    if(! b){
        for(auto &neigh : gr[cur]){
            if(neigh != par) {
                a2 = (a2 *  dfs(neigh, cur, true)) % mod;
            }
        }

        ans = (ans + a2) % mod;
    }

    return dp[cur][b] = ans % mod;
}

int main(){
    fio();

    ll n;
    cin>>n;
    for(ll x=1;x<n;x++){
        ll u,v;
        cin>>u>>v;

        gr[u].pb(v);
        gr[v].pb(u);
    }

    memset(dp, -1, sizeof dp);
    cout<<dfs(1,1,false);

    return 0;
}