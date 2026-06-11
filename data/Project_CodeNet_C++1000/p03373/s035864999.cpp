#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 1 << 30;
    ans = min(ans, ll(a * x + b * y));
    if (x > y)
    {
        ans = min(ans, ll(2 * c * y + a * (x - y)));
        ans = min(ans, ll(2 * c * x));
    }
    else
    {
        ans = min(ans, ll(2 * c * x + b * (y - x)));
        ans = min(ans, ll(2 * c * y));
    }

    cout << ans << endl;
    return 0;
}
