/**
*    author:  yuya1234
*    created: 24.06.2020 13:44:07
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int H, W;
    string S[50];
    bool flg = true;

    cin >> H >> W;

    REP(i, H)
    {
        cin >> S[i];
    }

    REP(i, H)
    {
        REP(j, W)
        {
            if (S[i][j] == '#')
            {
                flg = false;
                if (i < H - 1)
                {
                    if (S[i + 1][j] == '#')
                        flg = true;
                }
                if (j < W - 1)
                {
                    if (S[i][j + 1] == '#')
                        flg = true;
                }
                if (i > 0)
                {
                    if (S[i - 1][j] == '#')
                        flg = true;
                }
                if (j > 0)
                {
                    if (S[i][j - 1] == '#')
                        flg = true;
                }

                if (!flg)
                {
                    i = H;
                    j = W;
                    break;
                }
            }
        }
    }

    if (flg)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
