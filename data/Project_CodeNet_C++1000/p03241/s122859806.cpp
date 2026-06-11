#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    if (m % n == 0)
    {
        cout << m / n << endl;
    }
    else
    {
        int cd = 0;
        repi(i, m / n + 1, 1)
        {
            if (m % i == 0)
            {
                cd = i;
            }
        }
        cout << cd << endl;
    }
    return 0;
}