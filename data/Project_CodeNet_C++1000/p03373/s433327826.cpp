#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = a * x + b * y;
    ans = min(ans, c * 2 * max(x, y));
    if (x > y)
    {
        ans = min(ans, c * 2 * min(x, y) + (x - y) * a);
    }
    else
    {
        ans = min(ans, c * 2 * min(x, y) + (y - x) * b);
    }
    cout << ans << endl;
    return (0);
}
