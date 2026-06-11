#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin>>n;
    vector<long long>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vector<long long>dp(n,INT_MAX);
    dp[0] = 0;
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<=i+2;j++){
           if(j<n){
               dp[j] = min(dp[j],dp[i] + abs(h[i]-h[j]));
           }
        }
    }
    cout<<dp[n-1];
}
