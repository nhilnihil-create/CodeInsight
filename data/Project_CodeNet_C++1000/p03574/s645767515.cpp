#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<char>> ans(h + 1, vector<char>(w + 1, '0'));
    rep(i, h) cin >> s[i];
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == '.')
            continue;
        for (int a = i - 1; a <= i + 1; a++)
        {
            for (int b = j - 1; b <= j + 1; b++)
            {
                if (a < 0 || h <= a || b < 0 || w <= b)
                    continue;
                if (s[a][b] == '#')
                    ans[a][b] = '#';
                if ('0' <= ans[a][b] && ans[a][b] <= '9')
                    ans[a][b] += 1;
            }
        }
    }
    rep(i, h)
    {
        rep(j, w) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}