#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
int N, K;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    vector<ll> x(N), y(N);
    vector<ll> xary, yary;
    rep(i, N)
    {
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(xary.begin(), xary.end());
    sort(yary.begin(), yary.end());
    ll ans = 1ll * (xary[N - 1] - xary[0]) * (yary[N - 1] - yary[0]);

    rep(xi, N)
    {
        rep(xj, N)
        {
            rep(yi, N)
            {
                rep(yj, N)
                {
                    int num = 0;
                    ll lx = xary[xi], rx = xary[xj];
                    ll by = yary[yi], uy = yary[yj];
                    rep(i, N)
                    {
                        if (lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy) {
                            num++;
                        }
                    }
                    if (num >= K) {
                        ans = min(ans, 1ll * (rx - lx) * (uy - by));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}