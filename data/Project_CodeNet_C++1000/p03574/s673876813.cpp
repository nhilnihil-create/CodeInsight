#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                cout << s[i][j];
            }
            else
            {
                int ans = 0;
                for (int ri = -1; ri <= 1; ++ri)
                    for (int rj = -1; rj <= 1; ++rj)
                    {
                        int rri = i + ri;
                        int rrj = j + rj;
                        if (rri < 0 || rri >= h || rrj < 0 || rrj >= w)
                            continue;
                        if (s[rri][rrj] == '#')
                            ++ans;
                    }
                cout << ans;
            }
        }
        cout << endl;
    }
}