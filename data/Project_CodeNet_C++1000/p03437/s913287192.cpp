#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int x, y;
    cin >> x >> y;
    if (x % y == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << x << endl;
    }
    return 0;
}