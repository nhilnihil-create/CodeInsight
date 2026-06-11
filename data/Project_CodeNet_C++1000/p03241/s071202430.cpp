#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll m, n;
    cin >> n >> m;
    int ans = 1;
    for (ll i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            int a = i;
            int b = m / i;
            if (m / a >= n)
                ans = max(ans, a);
            if (m / b >= n)
                ans = max(ans, b);
        }
    }
    cout << ans << endl;
}