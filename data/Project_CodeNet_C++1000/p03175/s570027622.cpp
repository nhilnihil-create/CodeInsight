#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int n;
// col = 0 for parent = b,col = 1 for parent = w
// root ka col = 1
int dp[MAXN][2];
ll dfs(int curr,int p,int col) {
    if(dp[curr][col]!= 0) return dp[curr][col];
    // printf("%d %d %d\n",curr,p,col);
    ll ans = 1;
    ll prod1 = col;
    ll prod2 = 1;
    for(auto it: adj[curr]) {
        if(it != p) {
            if(col == 1) {
                prod1 = (prod1*dfs(it,curr,0))%mod;
                prod2 = (prod2*dfs(it,curr,1))%mod;
            } else {
                prod2 = (prod2*dfs(it,curr,1))%mod;
            }
        }
    }
    ans = (prod1 + prod2)%mod;
    return dp[curr][col] = ans;
}
int main() {
    cin>>n;
    int u,v;
    for(int i =0;i<n-1;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<dfs(1,0,1)<<"\n";

}