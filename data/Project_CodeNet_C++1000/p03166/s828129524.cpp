#include<bits/stdc++.h>
using namespace std;
int memoLongestPath(map<int, vector<int>>& ma, int s, vector<int>& dp){
    if(dp[s] != -1)
        return dp[s];

    if(ma[s].size() == 0){
        dp[s] = 0;
        return dp[s];
    }
    int mxm = 0;
    for(auto x:ma[s]){
        int cur = 1 + memoLongestPath(ma, x, dp);
        mxm = max(mxm, cur);
    }

    return dp[s] = mxm;

}

int main(){
    map<int, vector<int>> ma;
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        ma[x].push_back(y);
    }
    vector<int> dp(n+1, -1);
    int mxm = 0;
    for(int i=1; i<=n; i++){
        mxm = max(mxm, memoLongestPath(ma, i, dp));
    }
    cout<<mxm<<endl;
    return 0;
}
