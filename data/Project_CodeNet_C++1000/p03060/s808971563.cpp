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
    int v[n], c[n];
    repi(i, n, 0)
    {
        cin >> v[i];
    }
    repi(i,n,0){
        cin >> c[i];
    }
    int ans = 0;
    repi(bit, (1 << n), 0)
    {
        int x = 0, y = 0;
        repi(i, n, 0)
        {
            if (bit & (1 << i))
            {
                x += v[i];
                y += c[i];
            }
        }
        ans = max(ans, x - y);
    }
    cout << ans << endl;
    return 0;
}