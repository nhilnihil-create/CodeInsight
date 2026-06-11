#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    int dist[10][10];
    rep(i, 10)
    {
        rep(j, 10)
        {
            cin >> dist[i][j];
        }
    }
    vector<int> kab(h * w);
    rep(i, h * w) cin >> kab[i];

    //ワーシャルフロイド法
    rep(k, 10)
    {
        rep(i, 10)
        {
            rep(j, 10)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 0;
    rep(i, h * w)
    {
        ans += dist[kab[i]][1];
    }
    cout << ans << endl;
}