#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    vector<double> dp(n+1);
    dp[0] = 1; 
    for(int i=0;i<n;i++){
        for(int j=i+1;j>=0;j--){
            dp[j] = ((j==0)?0:dp[j-1]*(p[i]))+dp[j]*(1-p[i]);
        }
    }
    double ans=0.0;
    for(int i=0;i<n+1;i++){
        if(i>n-i) ans+=dp[i];
    }
    cout<<setprecision(10)<<fixed<<ans;
    return 0;
}