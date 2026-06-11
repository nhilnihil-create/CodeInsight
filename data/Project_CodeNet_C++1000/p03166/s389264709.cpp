#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(a, b) for (ll i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;
#define N 100005
const ll INF = 1000000001;
const ll MOD = 998244353 ; //1e9+7;

vector< vector<ll> > g(N);
//vector< pair<ll, pair< ll, ll > > > g(N);
ll vis[N] = {0}, par[N] = {0}, child[N] = {0}, dp[N] = {0};

void dfs(ll v){
    vis[v] = 1;
    for(auto u: g[v]){
        if(!vis[u]){
            dfs(u);
        }
        dp[v] = max(dp[v], 1 + dp[u]);
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    f(0, m-1){
        ll x, y;cin >> x >> y;
        g[x].pb(y);
    }
    ll ans = -INF;
    f(1, n){
        if(!vis[i]) dfs(i);
    }
    f(1, n) ans = max(ans, dp[i]);
    cout << ans << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    //ll t;cin >> t;for(ll index=1; index<=t; index++){
        //cout << "Case #" << index << ": " ;
        solve();
    //}
    return 0;
}
