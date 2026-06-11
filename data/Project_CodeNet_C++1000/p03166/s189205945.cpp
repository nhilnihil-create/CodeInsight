#include<bits/stdc++.h>
using namespace std;
/*

6 7
1 2
2 3
5 3
2 6
5 1
3 4
4 6

*/
int recursiveLongestPath(map<int, vector<int>>& ma, int s){
    if(ma[s].size() == 0)
        return 0;
    int mxm = 0;
    for(auto x:ma[s]){
        int cur = 1 + recursiveLongestPath(ma, x);
        mxm = max(mxm, cur);
    }
    return mxm;
}
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
    // int mxm = 0;
    // for(int i=1; i<=n; i++){
    //     mxm = max(mxm, recursiveLongestPath(ma, i));
    // }
    // cout<<"The length of the Longest Path(Recursive Implementation) is "<<mxm<<endl;
    vector<int> dp(n+1, -1);
    int mxm = 0;
    for(int i=1; i<=n; i++){
        mxm = max(mxm, memoLongestPath(ma, i, dp));
    }
    // cout<<"The length of the Longest Path(Memoization Implementation) is "<<mxm<<endl;
    cout<<mxm<<endl;
    return 0;
}
