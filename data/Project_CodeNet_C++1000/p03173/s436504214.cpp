#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
int main() {
    fast
    int n;
    cin>>n;
    ll a[n+1],prefix[n+1];;
    a[0]=0,prefix[0]=0;
    for(int i=1;i<n+1;++i) cin>>a[i],prefix[i]=prefix[i-1]+a[i];
    ll dp[n+1][n+1];
    for(int i=0;i<n+1;++i) dp[i][i] = 0;
    for(int i=1;i<n;++i) dp[i][i+1] = a[i]+a[i+1];
    for(int i=2;i<n;++i){
        for(int j=1;j+i<n+1;++j){
            dp[j][j+i] = LONG_MAX;
            for(int k=j;k<j+i;++k){
                dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+prefix[j+i]-prefix[j-1]);
            }
        }
    }
    cout<<dp[1][n];
}