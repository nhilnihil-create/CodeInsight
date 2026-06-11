#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int X[n], Y[m];
    if (x > y)
    {
        puts("War");
        return 0;
    }
    repi(i, n, 0)
    {
        cin >> X[i];
        if (X[i] >= y)
        {
            puts("War");
            return 0;
        }
    }
    repi(i, m, 0)
    {
        cin >> Y[i];
        if (Y[i] <= x)
        {
            puts("War");
            return 0;
        }
    }
    repi(i, n, 0)
    {
        repi(j, m, 0)
        {
            if (X[i] >= Y[j])
            {
                puts("War");
                return 0;
            }
        }
    }
    puts("No War");
    return 0;
}