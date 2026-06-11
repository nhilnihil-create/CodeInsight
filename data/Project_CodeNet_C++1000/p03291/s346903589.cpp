#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll mod = 1000000007;
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    if(s[0] == '?' || s[0] == 'A')dp[0][0] = 1;
    ll pow = 1;
    if(s[0] == '?')pow = 3;

    for(int i = 1; i < n; i++){
        if(s[i] == 'A'){
            dp[i][0] = (dp[i-1][0] + pow) % mod;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
        }else if(s[i] == 'B'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % mod;
            dp[i][2] = dp[i-1][2];
        }else if(s[i] == 'C'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = (dp[i-1][2] + dp[i-1][1]) % mod;
        }else{
            dp[i][0] = (3 * dp[i-1][0] + pow) % mod;
            dp[i][1] = (3 * dp[i-1][1] + dp[i-1][0]) % mod;
            dp[i][2] = (3 * dp[i-1][2] + dp[i-1][1]) % mod;
            pow = pow * 3 % mod;
        }
    }
    cout << dp[n-1][2] << endl;
}