//https://misteer.hatenablog.com/entry/ARC096-D
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main()
{
    ll N, C;
    cin >> N >> C;

    vector<ll> x(N + 2), v(N + 2);
    for (ll i = 1; i <= N; i++)
    {
        cin >> x[i] >> v[i];
    }
    x[0] = 0;
    x[N + 1] = C;

    ll cal = 0;
    vector<vector<ll>> dp(2, vector<ll>(100010, 0));

    for (ll i = 1; i <= N; i++)
    {
        cal -= x[i] - x[i - 1];
        cal += v[i];
        dp[0][i] = max(dp[0][i - 1], cal);
        // ここでそれまでのカロリーの最大値をメモ
    }

    cal = 0;
    for (ll i = N; i >= 1; i--)
    {
        cal -= x[i + 1] - x[i];
        cal += v[i];
        dp[1][i] = max(dp[1][i + 1], cal);
    }

    ll maxcal = 0;
    for (ll i = 0; i <= N; i++)
    {
        // 時計回り
        cal = dp[0][i] + dp[1][i + 1] - x[i];
        maxcal = max(maxcal, cal);

        // 反時計回り
        cal = dp[0][i] + dp[1][i + 1] - C + x[i + 1];
        maxcal = max(maxcal, cal);
    }

    cout << maxcal << endl;

    return 0;
}