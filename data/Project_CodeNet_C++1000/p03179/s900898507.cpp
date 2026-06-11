# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N = 3005, mod = 1e9 + 7, MOD = 5 * mod;
ll n, ans, dp[N][2];
string s;
int main(){
    cin >> n >> s;s = '#' + s;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++)dp[j][0] = dp[j][1], dp[j][1] = 0;
        for(int j = 1; j <= i; j++){
            if(s[i - 1] == '<')dp[j][1] = dp[j - 1][1] + dp[j - 1][0] - dp[0][0];
            if(s[i - 1] == '>')dp[j][1] = dp[j - 1][1] + dp[i - 1][0] - dp[j - 1][0];
            (dp[j][1] += MOD) %= mod;
        }
    }
    cout << dp[n][1] << endl;
}