#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define mod         1000000007
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi          vector<int>
#define nn          100001

int n;
vector<vi> graph;
int dp[nn][2];

// clr = 1 (white)
// clr = 0 (black)
int solve(int nd,bool clr,int par){
    if(dp[nd][clr] != -1)
        return dp[nd][clr];

    int ans = 0;
    int w1 = 1;
    for(auto nbr: graph[nd]){
        if(nbr != par)
            w1 = (w1 * solve(nbr, 0, nd)) % mod;
    }
    ans = (ans + w1) % mod;
    if(!clr){
        int w2 = 1;
        for(auto nbr: graph[nd]){
            if(nbr != par)
                w2 = (w2 * solve(nbr, 1, nd)) % mod;
        }
        ans = (ans + w2) % mod;
    }

    return dp[nd][clr] = ans;
}

int32_t main(){
    FAST;
    cin>>n;
    graph.resize(n+1);
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout<<solve(1,0,-1);
}