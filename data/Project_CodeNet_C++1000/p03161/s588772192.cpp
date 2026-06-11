#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main() {
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=0;
    }
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
        int x=INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++){
            x = min(dp[i-j]+abs(a[i]-a[i-j]), x);
            //cout<<i-j<<" ";
        }
        //cout<<endl;
        dp[i]=x;
    }
    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<dp[n-1];
}