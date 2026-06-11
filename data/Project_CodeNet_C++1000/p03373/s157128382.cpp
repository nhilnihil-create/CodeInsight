#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int mod = 1e9+7;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ab = c*2;
    int tmp, ans= 1e9;

    rep(i, x+y)
    {
        tmp = ab*i + a*max(0, x-i) + b*max(0, y-i);
        ans = min(ans, tmp);
    }

    cout << ans << endl;

}