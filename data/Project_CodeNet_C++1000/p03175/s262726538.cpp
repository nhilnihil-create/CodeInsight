#include<bits/stdc++.h>
using namespace std;

long long dp[100009][2];

long long m=1e9+7;

long long solve(int root, int color, int parent, vector<vector<int>>& g){
   // cout<<dp[root][color];
   if(dp[root][color]!=0)return dp[root][color];
    long long ans =1;
    //cout<<g[root][0];
   for(auto x: g[root]){
      //  cout<<x;
        if(x != parent){
            if(color==0)
            ans=(ans%m*((solve(x,0,root,g)%m+solve(x,1,root,g)%m)%m))%m;
           else
            ans=(ans%m*solve(x,0,root,g)%m)%m;
        }
    }
    return dp[root][color] = ans;
    
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>g(n+1);
    long long dp[n+1][2];

    
    
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout<<(solve(1,0,-1,g)+solve(1,1,-1,g))%m;
    
}