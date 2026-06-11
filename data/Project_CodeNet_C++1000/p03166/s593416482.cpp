#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = (n) - 1; i >= 0; i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define sz(x) ((long long)x.size())
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
 
auto clk=clock();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll INF = 1e18L+5;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
 
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<int> vint;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<bool> vb;

const ll N_MAX = 100005;
vvi adj(N_MAX);
vb vis(N_MAX);
vi dp(N_MAX);

void dfs(ll v){
    vis[v] = true;
    for(ll u : adj[v]){
        if(!vis[u])
            dfs(u);
        dp[v] = max(dp[v],dp[u]+1);
    }
}

void solve(){
    rep(i,N_MAX){
        adj[i].clear();
        vis[i] = false;
        dp[i] = 0;
    }

	ll n,m;
    cin>>n>>m;
    rep(i,m){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }

    fr(i,1,n)
        if(!vis[i])
            dfs(i);
    ll ans = *max_element(all(dp));
    cout<<ans;
}
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(11);
 
    ll t = 1;
    // cin>>t;
    while(t--)
        solve();
 
    // cout<<endl<<endl<<"Time elapsed: "<<((double)(clock()-clk)/CLOCKS_PER_SEC)*1000<<"ms"<<endl;
    return 0;
}