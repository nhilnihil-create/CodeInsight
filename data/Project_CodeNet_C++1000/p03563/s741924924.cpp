#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int r, g;
    cin >> r >> g;
    cout << 2 * g - r << endl;
    return 0;
}