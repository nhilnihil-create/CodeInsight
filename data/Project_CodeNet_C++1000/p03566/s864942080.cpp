#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;

int main()
{
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<double> t(N);
    vector<double> v(N);
    rep(i, N)
    {
        cin >> t[i];
    }
    rep(i, N)
    {
        cin >> v[i];
    }

    // 全体のT秒を求める
    int T = 0;
    rep(i, N)
    {
        T += t[i];
    }

    vector<double> maxV(2 * T + 1, (double)INF); // 0.5秒刻みで最大の速度

    // maxのスピードをv[i]で初期化
    int nowT = 0; // 現在の時間
    rep(i, N)
    {
        rep(ti, t[i])
        {
            int t1 = nowT + ti * 2;
            int t2 = nowT + ti * 2 + 1;
            maxV[t1] = min(maxV[t1], v[i]);
            maxV[t2] = min(maxV[t2], v[i]);
        }
        nowT += t[i] * 2;
        maxV[nowT] = min(maxV[nowT], v[i]);
    }

    // 0秒とT秒は0(静止)
    maxV[0] = maxV[T * 2] = 0.0;


    // 1秒間に1m/sしか速度が変わらない
    // 前から比較
    rep(ti, 2 * T + 1)
    {
        maxV[ti + 1] = min(maxV[ti + 1], maxV[ti] + 0.5);
    }
    // 後ろから比較
    for (int ti = 2 * T; ti >= 0; --ti) {
        maxV[ti] = min(maxV[ti], maxV[ti + 1] + 0.5);
    }

    double ans = 0.0;
    // 図形をにv軸に平行な辺を底として見て,x軸に平行な辺を縦として見ている
    rep(i, 2 * T + 1)
    {
        // (上底 + 下底) * 高さ / 2
        ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0;
    }

    cout << ans << endl;

    return 0;
}
