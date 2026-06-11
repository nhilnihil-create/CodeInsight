#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;
const int MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    ll n = S.size();

    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    dp[0][0] = 1;
    Rep (i, n) {
        Rep (j, 4) {
            if (S[i] != '?') dp[i+1][j] += dp[i][j];
            else dp[i+1][j] += 3 * dp[i][j];
            dp[i+1][j] %= MOD;
        }
        Rep (j, 3) {
            if (S[i] == 'A'+j || S[i] == '?') {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }

    cout << dp[n][3] << endl;

}