#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    rep (i, m)
        cin >> x[i];

    if (m == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(x.begin(), x.end());

    vector<int> dist(m - 1);
    rep (i, m - 1)
        dist[i] = x[i + 1] - x[i];

    sort(dist.begin(), dist.end(), greater<int>());

    ll ans = accumulate(dist.begin(), dist.end(), 0);
    int cnt = min(n - 1, m - 1);
    rep (i, cnt)
        ans -= dist[i];

    cout << ans << endl;
    return 0;
}