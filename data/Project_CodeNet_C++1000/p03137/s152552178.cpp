#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;
    if (n >= m)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<int> x(m, 0);
        repi(i, m, 0)
        {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        repi(i, m - 1, 0)
        {
            x[i] = abs(x[i] - x[i + 1]);
        }
        ll ans = 0;
        sort(x.begin(), x.end() - 1);
        repi(i, m - n, 0)
        {
            ans += x[i];
        }
        cout << ans << endl;
    }
    return 0;
}