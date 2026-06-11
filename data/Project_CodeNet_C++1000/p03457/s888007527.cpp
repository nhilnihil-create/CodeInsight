#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n, pt = 0, px = 0, py = 0;
    cin >> n;
    repi(i, n, 0)
    {
        int x, y, t;
        cin >> t >> x >> y;
        if (t - pt < abs(x - px) + abs(y - py))
        {
            cout << "No" << endl;
            return 0;
        }
        if((abs(x - px) + abs(y - py) - t + pt)&1){
            cout << "No" << endl;
            return 0;
        }
        pt = t;
        px = x;
        py = y;
    }
    cout << "Yes" << endl;
    return 0;
}