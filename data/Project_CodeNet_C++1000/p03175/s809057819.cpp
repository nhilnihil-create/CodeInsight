// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 100005; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

vector<ll> v[N];
ll dp[N][2];

void dfs(ll id,ll p)
{
    ll black = 1,white = 1;
    for(auto X:v[id])
    {
        if(X!=p)
        {
            dfs(X,id);
            white = (white * (dp[X][0] + dp[X][1])%MOD)%MOD;
            black = (black * (dp[X][1]))%MOD;
        }
    }
    dp[id][0] = black;
    dp[id][1] = white;
}

void solve()
{
    ll n;
    cin >> n;
    for(ll i=0,x,y;i<n-1;i++)
    {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);    
    } 
    dfs(1,0);
    ll ans = dp[1][0] + dp[1][1];
    ans %= MOD;
    cout<<ans;
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}