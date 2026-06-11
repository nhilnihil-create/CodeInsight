#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(100001,0);
    for(long long i=1;i<=100000;i++){
        long long com=1000000;
        for(long long j=1;i-j>=0;j*=6) com=min(com,dp[i-j]);
        for(long long j=1;i-j>=0;j*=9) com=min(com,dp[i-j]);
        dp[i]=com+1;
    }
    cout << dp[n] << endl;
}