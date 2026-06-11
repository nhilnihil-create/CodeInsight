#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, Y;
    cin >> N >> Y;
    for (ll i = 0; i <= N; ++i)
    {
        for (ll j = 0; j <= N - i; ++j)
        {
            ll k = N - i - j;
            if (k < 0)
            {
                break;
            }
            ll en = 10000 * i + 5000 * j + 1000 * k;
            if (en == Y)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
