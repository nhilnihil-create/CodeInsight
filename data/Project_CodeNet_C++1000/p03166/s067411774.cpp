
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>dp;
vector<vector<int> > chi,par;
int find(int i){
    int len=0;
    if(dp[i]!=-1)return dp[i];
    for(auto x:chi[i]){
        len=max(len,find(x)+1);
    }
    dp[i]=len;
    return dp[i];
}
int main(){
    int n, m ;
    cin>>n>>m;
    chi.resize(n+1);
    par.resize(n+1);
    dp.resize(n+1,-1);
    for(int i = 0 ; i < m ; i ++ ) {
        int a, b;
        cin>>a>>b;
        chi[a].push_back(b);
        par[b].push_back(a);
    }int ans=0;
    for(int i = 1 ; i <= n ; i++ ){
        if(par[i].size()==0){
            dp[i]=find(i);
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<endl;
}
