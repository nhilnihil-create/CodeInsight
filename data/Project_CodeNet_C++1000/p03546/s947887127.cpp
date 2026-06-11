#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;

int mp[10][10];
int minMP[10][10];
void warshallFloyd()
{
    rep(i, 10) rep(j, 10) minMP[i][j] = INF;
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    rep(i, 10) rep(j, 10) cin >> mp[i][j];

    int wall[210][210];
    rep(h, H) rep(w, W) cin >> wall[h][w];

    warshallFloyd();

    int ans = 0;
    rep(h, H)
    {
        rep(w, W)
        {
            if (wall[h][w] == -1)
                continue;
            ans += mp[wall[h][w]][1];
        }
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
