#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a + b) > (c + d) ? "Left" : (a + b) == (c + d) ? "Balanced" : "Right") << endl;
    return 0;
}