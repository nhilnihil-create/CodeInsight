#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        swap(a, b);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a > b)
    {
        swap(a, b);
    }
    cout << c*10 + b + a << endl;
    return 0;
}