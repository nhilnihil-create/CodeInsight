#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define LLINF (1e18)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll dp[100010][4];
// dp[i+1][j]:=i文字目まで見た時に、"ABC"のうちj番目まで照合したものの個数

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i] == '?')
            {
                dp[i + 1][j] += (dp[i][j] * 3 % MOD);
                dp[i + 1][j] %= MOD;
            }
            else
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
        }
        if (s[i] == 'A' || s[i] == '?')
        {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] %= MOD;
        }
        if (s[i] == 'B' || s[i] == '?')
        {
            dp[i + 1][2] += dp[i][1];
            dp[i + 1][2] %= MOD;
        }
        if (s[i] == 'C' || s[i] == '?')
        {
            dp[i + 1][3] += dp[i][2];
            dp[i + 1][3] %= MOD;
        }
    }
    cout << dp[n][3] << endl;
}