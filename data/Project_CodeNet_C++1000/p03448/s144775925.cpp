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
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;

    rep(i, a + 1)
    {
        rep(j, b + 1)
        {
            int num = x / 50 - 10 * i - 2 * j;
            if (0 <= num && num <= c)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
