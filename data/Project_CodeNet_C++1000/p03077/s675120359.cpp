#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll n;
    cin >> n;
    ll m = INF;
    repi(i, 5, 0)
    {
        ll tmp;
        cin >> tmp;
        m = min(tmp, m);
    }
    ll div = (n + m - 1) / m - 1;
    cout << 5LL + div << endl;
    return 0;
}