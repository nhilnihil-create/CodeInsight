#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
ll mod=1e9+7;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactice problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output
ll n;
vector<ll> adj[100005];
ll dp[100005][2];

void dfs(ll u, ll p){
    for(auto i=adj[u].begin(); i!=adj[u].end(); i++){
        if(*i != p){
            dfs(*i, u);
            dp[u][1] = (dp[u][1]*((dp[*i][0]+dp[*i][1])%mod))%mod;
            dp[u][0] = (dp[u][0]*dp[*i][1])%mod;
        }
    }
}

int main()
{ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < n+1; ++i)
    {
        dp[i][0]=1;
        dp[i][1]=1;
    }

    dfs(1, -1);

    cout<<(dp[1][0]+dp[1][1])%mod;

    return 0;
}
