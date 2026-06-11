#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    auto f = [](ll a) -> ll {
        ll s = 0;
        while (a % 2 == 0)
        {
            s++;
            a /= 2;
        }
        return s;
    };
    repi(i, n, 0)
    {
        ll a;
        cin >> a;
        ans += f(a);
    }
    cout << ans << endl;
    return 0;
}