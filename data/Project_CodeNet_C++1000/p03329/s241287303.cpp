#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod = 1e9+7;
const int maxn=2e5+7;

int dfs(int &n,int curn,vector<int> &dp){
    if(n==curn){
        return 0;
    }
    
    if(curn>n) return 1e6+1;
    if(dp[curn] != -1) return dp[curn];
    int ways = 1+dfs(n,curn+1,dp);
    for(int i=1;i<=6;i++){
        ways = min(ways,1+dfs(n,curn+pow(6,i),dp));
    }
    for(int i=1;i<=5;i++){
        ways = min(ways,1+dfs(n,curn+pow(9,i),dp));
    }
    return dp[curn] = ways;
}

int main(){
    int n;
    cin>>n;    
    vector<int> dp(n+1,-1);
    cout<<dfs(n,0,dp);    
}