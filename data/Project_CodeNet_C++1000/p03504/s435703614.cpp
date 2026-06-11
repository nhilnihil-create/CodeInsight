#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
static const int MAX_T = 123456;
int N, C;
int imos[30][MAX_T]; // imos[i][j] := チャンネルiで時刻jに録画をする

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> C;
    rep(i, N)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --c;
        ++imos[c][a];
        --imos[c][b];
    }

    // imos法
    rep(i, C)
    {
        rep(j, MAX_T - 1)
        {
            imos[i][j + 1] += imos[i][j];
        }
    }
    rep(i, C)
    {
        rep(j, MAX_T - 1)
        {
            if (imos[i][j] == 0 && imos[i][j + 1] == 1) {
                ++imos[i][j]; // 録画を0.5秒早める
            }
        }
    }
    int ans = 0;
    rep(j, MAX_T)
    {
        int cnt = 0;
        rep(i, C)
        {
            if (imos[i][j]) {
                ++cnt;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}