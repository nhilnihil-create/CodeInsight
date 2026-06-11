#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    vector<int> v(5);
    rep(i, 5) cin >> v[i];

    int ans = 1001001001;
    rep(i, 5)
    {
        int res = 0;
        rep(j, 5)
        {
            if (i == j)
            {
                res += v[j];
            }
            else
            {
                res += (v[j] + 9) / 10 * 10;
            }
        }
        ans = min(res, ans);
    }

    cout << ans << '\n';
    return 0;
}
