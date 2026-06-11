#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//ABC 99 c.cpp
int main() {
    int MX = 10000000;
    int n;
    cin >> n;

    int I=0;
    while(pow(6,I+1) <= n) I++;
    // cout << I << endl;
    int J = 0;
    while(pow(9,J+1) <= n) J++;
    // cout << J << endl;

    vector<int> dp(n+1);
    rep(i,n+1) dp[i] = MX;
    dp[0] =  0;
    int ind = 0;
    for(int i =0;i < n;i++){
        dp[i+1] = min(dp[i+1],dp[i] + 1);
        for(int j = 1;j<=J;j++){
            ind = pow(9,j);
            if(i+ind<=n) dp[i+ind] = min(dp[i+ind],dp[i] + 1);
        }
        for(int j = 1;j<=I;j++){
            ind = pow(6,j);
            if(i+ind<=n) dp[i+ind] = min(dp[i+ind],dp[i] + 1);
        }
    }

    int ans = dp[n];
    cout << ans << endl;
}