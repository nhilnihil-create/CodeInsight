#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const ll INF = 1001001001;

ll dp[200000][5];

int main(){
    string s; cin >> s;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 4; j++){
            if(s[i] == '?'){
                dp[i+1][j] += dp[i][j] * 3 % mod;
                dp[i+1][j] %= mod;
            }
            else{
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
        }
        if(s[i] == 'A' || s[i] == '?'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= mod;
        }
        if(s[i] == 'B' || s[i] == '?'){
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= mod;
        }
        if(s[i] == 'C' || s[i] == '?'){
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= mod;
        }
    }
    cout << dp[s.size()][3] << endl;
}
