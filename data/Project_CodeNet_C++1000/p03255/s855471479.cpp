#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    cin >> N >> X;
    vector<ll> x(N), s(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    sort(x.rbegin(), x.rend());
    for (int i = 0; i < N; i++)
    {
        s[i] = (i == 0 ? x[i] : s[i - 1] + x[i]);
    }
    ll ret = 1e18;
    for (ll i = 1; i <= N; i++)
    {
        bool ovf = false;
        ll sum = N * X + i * X;
        for (int index = 1; index <= (N - 1) / i + 1; index++)
        {
            int st = (index - 1) * i, gt = min(N - 1, index * i - 1);
            if (index == 1)
            {
                sum += 5 * s[gt];
            }
            else
            {
                sum += (2 * index + 1) * (s[gt] - s[st - 1]);
            }
            if (sum > 1e18)
            {
                ovf = true;
                break;
            }
        }
        if (ovf)
            continue;
        ret = min(ret, sum);
    }
    cout << ret << endl;
}
