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

    sort(x.begin(), x.end());

    vector<int> dist(m - 1);
    rep (i, m - 1)
        dist[i] = x[i + 1] - x[i];

    sort(dist.begin(), dist.end(), greater<int>());

    int cnt = min(n - 1, m - 1);
    ll ans = accumulate(dist.begin(), dist.end(), -accumulate(dist.begin(), dist.begin() + cnt, 0));

    cout << ans << endl;
    return 0;
}