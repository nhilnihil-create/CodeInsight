#include<bits/stdc++.h>

#define inp 200005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007 
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }

using namespace std;

// Pick yourself up, 'cause...

vector<int> g[inp];
int n;
vector<vector<int>> dp(inp,vector<int>(2,0));
vector<bool> vis(inp,false);

void func(int cn , int p) // 0 white , 1 black
{
    if(vis[cn]) return;

    vis[cn]=true;

    ll white = 1;
    ll black = 1;
    for(int c:g[cn])
    {
        if(c==p) continue;
        func(c , cn);
        white *= (dp[c][0] + dp[c][1]);
        black *= dp[c][0];
        white%=mod;
        black%=mod;
    }
    dp[cn][0]=white;
    dp[cn][1]=black;
}

int main()
{
    jaldi

    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    func(1 , 0);
     
    cout << ( dp[1][0] + dp[1][1] ) % mod;
    
    return 0;
}