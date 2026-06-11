#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main()
{
    string s; cin >> s;
    int n = s.size();
    for(auto &i: s)i -= (i != '?' ? 'A' : 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(4)); //dp[i] := i文字目まで見てj = 0が未A, j = 3がABC
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {

        //一致のやつ
        for(int j = 0; j < 3; j++) {
            if(s[i] == '?' || s[i] == j) {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }
        }
        for(int j = 0; j < 4; j++){dp[i + 1][j] += dp[i][j] * (s[i] == '?' ? 3 : 1);dp[i + 1][j] %= mod;}
    }
    cout << dp[n][3] << endl;
}