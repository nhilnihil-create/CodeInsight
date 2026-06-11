#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int dp[100001][2];
vector<int>v[100001];
void dfs(int node,int par)
{
    dp[node][0]=1;
    dp[node][1]=1;
    for(auto c:v[node])
    {
        if(c!=par)
        {
            dfs(c,node);
            dp[node][1]=(dp[node][1]*dp[c][0])%mod;
            dp[node][0]=(dp[node][0]*(dp[c][1]+dp[c][0]))%mod;
        }
    }
}
int32_t main() {
    nitin;
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0,-1);
    cout<<(dp[0][0]+dp[0][1])%mod<<endl;
    return 0;
}