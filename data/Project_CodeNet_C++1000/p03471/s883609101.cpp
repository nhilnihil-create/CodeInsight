/**
*    author:  yuya1234
*    created: 24.06.2020 10:10:02
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

    int n;
    ll y;
    bool flg = false;

    cin >> n >> y;

    FOR(i, 0, n)
    {
        FOR(j, 0, n - i)
        {
            if (i * 10000 + j * 5000 + (n - i - j) * 1000 == y)
            {
                cout << i << " " << j << " " << n - i - j << endl;
                flg = true;
                i = j = n;
            }
        }
    }

    if (!flg)
    {
        cout << "-1 -1 -1" << endl;
    }

    return 0;
}