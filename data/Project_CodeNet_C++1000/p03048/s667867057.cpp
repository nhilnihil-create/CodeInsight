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
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;

    rep(i, n + 1)
    {
        rep(j, n + 1)
        {
            if ((n - (i * r + j * g)) % b == 0 && (n - (i * r + j * g)) >= 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return (0);
}
