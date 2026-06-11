#include <bits/stdc++.h>
using namespace std;
int soln(vector<vector<int>>a){
    int n=a.size();
    int dp[n][3];
    //base case
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for(int i=1;i<n;i++){
        dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=a[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    int i=n-1;
    return max(dp[i][0],max(dp[i][1],dp[i][2]));
}
int main() {
    int n;cin>>n;
    vector<vector<int>>a;
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        a.push_back({x,y,z});
    }
    cout<<soln(a);
}
