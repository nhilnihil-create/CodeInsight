#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int negCnt = 0;
    vector<ll> a(n);
    rep (i, n)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            a[i] = x * -1;
            negCnt++;
        }
        else
            a[i] = x;
    }

    ll ans;
    sort(a.begin(), a.end());
    if (negCnt % 2)
        ans = accumulate(a.begin() + 1, a.end(), 0LL + a[0] * -1);
    else
        ans = accumulate(a.begin(), a.end(), 0LL);

    cout << ans << endl;
    return 0;
}