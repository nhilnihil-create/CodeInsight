#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,dp[100005][2];
vector<int>a[100005];
bool check[100005]={false};
void dfs(int node){
    if(check[node]==true) return ;
    check[node]=true;
    for(auto i=a[node].begin();i!=a[node].end();i++){
        if(check[*i]==false){
            dfs(*i);
            dp[node][0]=dp[node][0]*((dp[*i][1]+dp[*i][0])%mod)%mod;
            dp[node][1]=dp[node][1]*dp[*i][0]%mod;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) dp[i][0]=1,dp[i][1]=1;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    cout<<(dp[1][0]+dp[1][1])%mod;
    return 0;
}
