#include <bits/stdc++.h>
using namespace std;
 
int minFrog2(int n,int k,vector<int>height){
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=i;j>i-k-1 && j>=0;j--){
            dp[i]=min(dp[i],dp[j]+abs(height[i]-height[j]));
        }
        
    }
    return dp[n-1];
}
 
int main() {
    int n;cin>>n;
    int k; cin>>k;
    int h;
    vector<int> height;
    for(int i=0;i<n;i++){
        cin>>h;
        height.push_back(h);
    }
    cout<<minFrog2(n,k,height);
}