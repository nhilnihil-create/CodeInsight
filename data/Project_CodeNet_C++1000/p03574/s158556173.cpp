/**
*    author:  yuya1234
*    created: 24.06.2020 11:31:09
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)

char itoa(int i)
{
    switch (i)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    default:
        return '0';
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int H, W, cnt = 0, cntB;
    string S[52];
    int Bh[2500], Bw[2500];

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
                Bh[cnt] = i;
                Bw[cnt] = j;
                cnt++;
            }
        }
    }

    REP(i, H)
    {
        REP(j, W)
        {
            if (S[i][j] == '.')
            {
                cntB = 0;
                REP(a, cnt)
                {
                    if ((Bh[a] == i + 1 && Bw[a] == j - 1) 
                    || (Bh[a] == i + 1 && Bw[a] == j) 
                    || (Bh[a] == i + 1 && Bw[a] == j + 1) 
                    || (Bh[a] == i && Bw[a] == j - 1) 
                    || (Bh[a] == i && Bw[a] == j + 1) 
                    || (Bh[a] == i - 1 && Bw[a] == j - 1) 
                    || (Bh[a] == i - 1 && Bw[a] == j) 
                    || (Bh[a] == i - 1 && Bw[a] == j + 1))
                    {
                        cntB++;
                    }
                }
                S[i][j] = itoa(cntB);
            }
        }
    }

    REP(i, H)
    {
        cout << S[i] << endl;
    }

    return 0;
}
