#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    int x[n], y[n], h[n];
    repi(i, n, 0)
    {
        cin >> x[i] >> y[i] >> h[i];
    }

    repi(cx, 101, 0)
    {
        repi(cy, 101, 0)
        {
            repi(i, n, 0)
            {
                int H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                bool state = true;
                repi(j, n, 0)
                {
                    if (h[j] != max(0LL, H - abs(x[j] - cx) - abs(y[j] - cy)))
                    {
                        state = false;
                        break;
                    }
                }
                if (state && H > 0)
                {
                    cout << cx << " " << cy << " " << H << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}