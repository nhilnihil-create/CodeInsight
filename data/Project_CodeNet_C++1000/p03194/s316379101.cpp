#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll n, p;
    cin >> n >> p;
    if (n == 1)
        cout << p << endl;
    else
    {
        ll ans = 1;
        for (ll i = 2; i * i <= p; i++)
        {
            ll cnt = 0;
            while (p % i == 0)
            {
                cnt++;
                p /= i;
            }
            if (cnt >= n)
            {
                repi(j, cnt / n, 0)
                {
                    ans *= i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}