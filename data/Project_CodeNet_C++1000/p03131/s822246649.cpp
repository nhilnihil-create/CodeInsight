#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 1;
    rep(i, k)
    {
        if (ans < a || k - i < 2 || a + 1 >= b)
            ans++;
        else
            ans -= a, i++, ans += b;
    }
    cout << ans << endl;
}