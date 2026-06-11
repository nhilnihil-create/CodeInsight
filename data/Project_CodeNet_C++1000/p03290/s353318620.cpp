#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
long long dp[100010];
long long h[100010];
const int MOD = 1000000007;

int main()
{
    int d, g; cin >> d >> g;
    int p[11],c[11];
    rep(i, d) cin >> p[i] >> c[i];

    ll ans = INF;
    rep(i, 1 << d)
    {
        ll tot = 0, cnt = 0;
        rep(j, d)
        {
            if (i >> j & 1)
            {
                tot += p[j] * (j + 1) * 100 + c[j];
                cnt += p[j];
            }
        }
        if (tot >= g) ans = min(ans, cnt);
        else
        {
            for (int j = d-1; j >= 0; --j)
            {
                if (i >> j & 1) continue;
                rep(k, p[j])
                {
                    if (tot >= g) break;
                    tot += 100 * (j + 1);
                    cnt++;
                    //cout << j << endl;
                }
            }
            ans = min(ans, cnt);
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}