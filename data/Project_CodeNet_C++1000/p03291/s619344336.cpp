#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ciosup;
    string s;
    cin >> s;
    int sz = s.size();
    vector<vector<ll>> dp(4, vector<ll>(sz + 8, 0));
    REP(i,sz+1){
        dp[3][i] = 1;
    }
    REP(i, sz)
    {
        if (s[i] == 'A'){
            dp[0][i + 1] = (dp[0][i] + dp[3][i]) % MOD;
            dp[1][i + 1] = dp[1][i];
            dp[2][i + 1] = dp[2][i];
            dp[3][i + 1] = dp[3][i];
        }
        else if (s[i] == 'B')
        {
            dp[1][i + 1] = (dp[1][i] + dp[0][i]) % MOD;
            dp[0][i + 1] = dp[0][i];
            dp[2][i + 1] = dp[2][i];
            dp[3][i + 1] = dp[3][i];
        }else if (s[i] == 'C')
        {
            dp[2][i + 1] = (dp[2][i] + dp[1][i]) % MOD;
            dp[0][i + 1] = dp[0][i];
            dp[1][i + 1] = dp[1][i];
            dp[3][i + 1] = dp[3][i];
        }else
        {
            dp[0][i + 1] = (3*dp[0][i] % MOD + dp[3][i]) % MOD;
            dp[1][i + 1] = (3*dp[1][i] % MOD + dp[0][i]) % MOD;
            dp[2][i + 1] = (3*dp[2][i] % MOD + dp[1][i]) % MOD;
            dp[3][i + 1] = dp[3][i] * 3 % MOD;
        }
    }
    cout << dp[2][sz] << endl;
}