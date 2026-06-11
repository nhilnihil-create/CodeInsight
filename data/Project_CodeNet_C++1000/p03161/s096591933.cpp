#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>A;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=max(0,i-k);j<i;j++){
            dp[i]=min(dp[i],dp[j]+abs(A[i]-A[j]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}