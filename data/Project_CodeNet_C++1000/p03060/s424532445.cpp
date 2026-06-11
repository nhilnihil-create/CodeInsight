#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;

    vector<int> v(n), c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];

    int res = 0;
    rep(i, n)
    {
        if (v[i] - c[i] > 0)
        {
            res += v[i] - c[i];
        }
    }

    cout << res << '\n';
    return 0;
}
