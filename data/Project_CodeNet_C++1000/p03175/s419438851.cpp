#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007
 
const int mxN = 1e5 + 1;
ll n;
vt<ll> adj[mxN];
vector<array<ll, 2>> dp(mxN, {1, 1});

void dfs(int u, int p = -1)
{
    for(int v: adj[u])
    {
        if(v == p)
            continue;
        dfs(v, u);
        dp[u][0] *= (dp[v][0] + dp[v][1]) % mod;
        dp[u][1] *= dp[v][0];
        dp[u][0] %= mod;
        dp[u][1] %= mod;
    }
}
 
 
int main()
{
FIO
 
    cin >> n;
    ll u, v;
    For(n-1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    cout << (dp[1][0] + dp[1][1]) % mod ;
}