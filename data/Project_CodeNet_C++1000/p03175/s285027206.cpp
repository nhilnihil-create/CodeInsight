#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree[100001];
int dp[100001][2];

int solve(int u, int constraint, int pr)
{
    if(dp[u][constraint] != -1){
        return dp[u][constraint];
    }
    int ans = 0;
    int w1 = 1;
    for(int child:tree[u]){
        if(child != pr){
            w1 = (w1*solve(child,0,u))%1000000007;
        }
    }
    ans = ans+w1;
    if(!constraint){
        int w2 = 1;
        for(int child:tree[u]){
            if(child!=pr){
                w2 = (w2*solve(child,1,u))%1000000007;
            }
        }
        ans = (ans+w2)%1000000007;
    }
    return dp[u][constraint] = ans;

}
int32_t main() {
    int n;cin>>n;
    for(int i = 1;i<n;i++){
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(1,0,-1);


    
}
