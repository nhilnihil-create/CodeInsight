#include <iostream>
#define ll long long

using namespace std;

const int MOD = 1e9+7;
int dp[3007][3007];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[0][1] = 1;
    //cout << dp[0][1] << endl;
    for(int i = 1; i < n; i++){
        int ps[3007][2] = {0};
        ps[1][0] = dp[i-1][1];
        for(int j = 2; j <= i; j++){
            ps[j][0] = (ps[j-1][0] + dp[i-1][j]) % MOD;
        }
        ps[i][1] = dp[i-1][i];
        for(int j = i-1; j >= 1; j--){
            ps[j][1] = (ps[j+1][1] + dp[i-1][j]) % MOD;
        }
        for(int j = 1; j <= i+1; j++){
            if(s[i-1] == '>'){
                dp[i][j] = ps[j][1];
            }
            else{
                dp[i][j] = ps[j-1][0];
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + dp[n-1][i]) % MOD;
    }
    cout << ans;
}
