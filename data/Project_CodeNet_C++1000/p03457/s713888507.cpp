/**
*    author:  yuya1234
*    created: 24.06.2020 11:12:30
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

    int N;
    int t[100001], x[100001], y[100001];
    bool flg = true;

    cin >> N;

    t[0] = x[0] = y[0] = 0;

    FOR(i, 1, N)
    {
        cin >> t[i] >> x[i] >> y[i];
        int time = t[i] - t[i - 1];
        int dx = abs(x[i] - x[i - 1]);
        int dy = abs(y[i] - y[i - 1]);

        if (time < dx + dy || (time - dx + dy) % 2 == 1)
        {
            flg = false;
            break;
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