#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    
    vector<vector<long long int>> dp(n+1, vector<long long int>(4));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<4; j++){
            dp[i][j] = dp[i-1][j];
            if(s[i-1] == '?') dp[i][j] *= 3;
        }

        if(s[i-1] == 'A') dp[i][1] += dp[i-1][0];
        if(s[i-1] == 'B') dp[i][2] += dp[i-1][1];
        if(s[i-1] == 'C') dp[i][3] += dp[i-1][2];
        if(s[i-1] == '?'){
            for(int j=0; j<3; j++){
                dp[i][j+1] += dp[i-1][j];
            }
        }

        for(int j=0; j<4; j++){
            dp[i][j] %= MOD;
            //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    cout << dp[n][3] << endl;
    return 0;
}