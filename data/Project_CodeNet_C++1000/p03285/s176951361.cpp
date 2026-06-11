#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    rep(i, (n + 3) / 4)
    {
        int x = 4 * i;
        if (n % 4 == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        if ((n - x) % 7 == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
