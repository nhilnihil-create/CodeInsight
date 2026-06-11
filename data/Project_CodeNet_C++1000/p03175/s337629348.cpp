#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
const int N=1e5+10,mod=1e9+7,OO=0x3f3f3f3f;
typedef long long ll;
ll n,x,y,dp[N][2];
vector<int>adj[N];
void dfs(int u=1,int p=-1){
    dp[u][0]=dp[u][1]=1;
    for(auto v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        dp[u][0]=(dp[u][0]*(dp[v][1]+dp[v][0]))%mod;
        dp[u][1]=(dp[u][1]*dp[v][0])%mod;
    }


}
int main()
{
    Elhabashy
    input();
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}
