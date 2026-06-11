#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w, n;
    cin >> h >> w >> n;
    map<P, int> mp;
    vector<int> x(n), y(n);
    vector<vector<int>> vx(w + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        mp[P(x[i], y[i])]++;
        vx[y[i]].push_back(x[i]);
    }
    for (int i = 1; i <= w; i++)
    {
        sort(vx[i].begin(), vx[i].end());
        vx[i].push_back(h + 1);
    }
    // dp[j] := j 列目に入れる最小の x 座標
    vector<int> dp(w + 1, h + 1);
    dp[1] = 1;
    int res = *(upper_bound(vx[1].begin(), vx[1].end(), 1));
    for (int j = 2; j <= w; j++)
    {
        for (int i = dp[j - 1] + 1; i <= h; i++)
        {
            if (mp[P(i, j)])
                continue;
            dp[j] = i;
            break;
        }
        auto itr = upper_bound(vx[j].begin(), vx[j].end(), dp[j]);
        if(itr==vx[j].end()) continue;
        res = min(res, *itr);
    }
    cout << res - 1 << endl;
}
