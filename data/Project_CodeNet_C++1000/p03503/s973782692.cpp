#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    int F[n][10], P[n][11];
    rep(i, n)
    {
        rep(j, 10) cin >> F[i][j];
    }
    rep(i, n)
    {
        rep(j, 11) cin >> P[i][j];
    }
    //以上入力まで

    //ビット全探索
    ll ans = -MOD;
    for (int i = 1; i < (1 << 10); i++)
    {
        ll res = 0;
        rep(j, n)
        {
            int cnt = 0;
            rep(k, 10)
            {
                if ((i & (1 << k)) && F[j][k])
                    cnt++;
            }
            res += P[j][cnt];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}