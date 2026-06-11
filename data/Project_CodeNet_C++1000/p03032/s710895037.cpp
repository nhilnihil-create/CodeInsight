#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    rep (i, n)
        cin >> v[i];

    ll ans = 0;
    for (int l = 0; l <= min(n, k); l++)
        for (int r = 0; l + r <= min(n, k); r++)
        {
            if (l + r > n)
                continue;
            vector<ll> sum;
            ll ret = 0;
            rep (i, l)
            {
                sum.push_back(v[i]);
                ret += v[i];
            }
            rep (i, r)
            {
                sum.push_back(v[n - 1 - i]);
                ret += v[n - 1 - i];
            }
            sort(sum.begin(), sum.end());

            int size = sum.size();
            rep (i, size)
            {
                if (i >= k - l - r || sum[i] >= 0)
                    break;
                ret -= sum[i];
            }
            ans = max(ans, ret);
        }

    cout << ans << endl;
    return 0;
}