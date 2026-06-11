#include <bits/stdc++.h>
using namespace std;
vector<int> mp[1100000];
int dp[1100000];

int check(int i){
    if(dp[i]!=-1) return dp[i];
    int re=0;
    for(int j=0;j<mp[i].size();j++){
        re=max(re,check(mp[i][j])+1);
    }
    dp[i]=re;
    return re;
}


int main() {
    int n,e;
    cin>>n>>e;
    for(int i=0;i<1100000;i++) dp[i]=-1;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
    }
    int ans=0;
    for(int i=0;i<1100000;i++){
        ans=max(ans,check(i));
    }
    
    cout<<ans;
    
    return 0;
}