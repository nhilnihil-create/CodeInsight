#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = s[0] - '0';
    dp[0][1] = s[0] - '0' - 1;
    for(int i=0; i+1<n; i++){
        dp[i+1][0] = dp[i][0] + s[i+1] - '0';
        dp[i+1][1] = dp[i][1] + 9;
        if(s[i+1] - '0' >= 1) dp[i+1][1] = max(dp[i+1][1], dp[i][0] + (s[i+1] - '0' - 1));
    }
    //cout << dp[n-1][0] << " " << dp[n-1][1] << endl;
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}