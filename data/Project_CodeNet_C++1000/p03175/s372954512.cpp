
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;

#define Max 1000001
#define intinf 2147483647
#define longlonginf 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vint vector<int>
#define vll vector<long long>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define F(i,n) for(int i = 0;i<n;i++)
#define Fr(i,l,r) for(int i = l;i <= r;i++)
#define rF(i,n) for(int i = n-1;i>=0;i--)
#define all(arr) arr.begin(),arr.end()


ll Lpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2)
            ans = (ans*a);
        a = (a*a);
        b = b/2;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

int n;
vector<vector<int>> adj(100005);

vector<vector<ll>> dp(100005,vector<ll>(2,0));

void dfs(int node,int p)
{
    for(auto x : adj[node])
    {
        if(x != p)
            dfs(x,node);
    }

    ll w = 1;
    ll b = 1;
    
    for(auto x : adj[node])
    {
        if(x != p)
        {
            w = w*(dp[x][0] + dp[x][1])%MOD2;
            b = b*dp[x][0]%MOD2;
        }
    }
    
    dp[node][0] = w;
    dp[node][1] = b;
}

signed main()
{
    fastio;
    
    cin >> n;
    int a,b;
    F(i,n-1)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,1);
    
    
    cout << (dp[1][0] + dp[1][1])%MOD2 << endl;
    
    return 0;
}
