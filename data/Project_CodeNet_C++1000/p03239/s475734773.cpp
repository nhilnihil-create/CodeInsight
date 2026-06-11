#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> c(n), time(n);
    rep(i, n) cin >> c[i] >> time[i];

    int res = 1001001001;
    rep(i, n)
    {
        if (time[i] <= t)
        {
            res = min(res, c[i]);
        }
    }

    if (res == 1001001001)
    {
        cout << "TLE" << '\n';
    }
    else
    {
        cout << res << '\n';
    }
    return 0;
}
