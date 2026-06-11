#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n), s(n), f(n);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    c[n - 1] = 0;
    s[n - 1] = f[n - 1] = 1;

    rep(i, n - 1)
    {
        int ans = 0;
        for (int j = i; j < n - 1; ++j)
        {
            int t;
            if (ans % f[j] != 0)
                t = ans / f[j] + 1;
            else
                t = ans / f[j];
            ans = max(s[j], t * f[j]);
            ans += c[j];
        }

        cout << ans << endl;
    }
    cout << 0 << endl;
}