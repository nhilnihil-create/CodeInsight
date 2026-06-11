#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>v[i][j];
    }
    vector<int> dp(3);
    dp[0]=v[0][0];
    dp[1]=v[0][1];
    dp[2]=v[0][2];
    
    for(int i=1;i<n;i++){
        vector<int> m(3);
        m[0]=max(dp[1],dp[2]) + v[i][0];
        m[1]=max(dp[0],dp[2]) + v[i][1];
        m[2]=max(dp[0],dp[1]) + v[i][2];
        dp[0]=m[0];
        dp[1]=m[1];
        dp[2]=m[2];
    }
    int max=-1;
    for(int i=0;i<3;i++) if(dp[i]>max) max=dp[i];
    cout<<max;
    return 0;
}