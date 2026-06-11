#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int dish[5], ans = 0;
    repi(i, 5, 0)
    {
        cin >> dish[i];
        ans += (dish[i] + 9) / 10 * 10;
        dish[i] = (dish[i] % 10 ? 10 - dish[i] % 10 : 0);
    }
    sort(dish, dish + 5);
    cout << ans - dish[4] << endl;
    return 0;
}