#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
typedef pair<int, int> P;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dat(11, vector<int>(11));
    rep(i, 10)
    {
        rep(j, 10)
        {
            cin >> dat[i][j];
        }
    }
    rep(k, 10)
    {
        rep(i, 10)
        {
            rep(j, 10)
            {
                dat[i][j] = min(dat[i][j], dat[i][k] + dat[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            int a;
            cin >> a;
            if (a == -1)
                continue;
            ans += dat[a][1];
        }
    }
    cout << ans << endl;
}