#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    int ans = b[n - 1] - b[0], pos = 0;
    while (pos < n)
    {
        vector<int> v, w;
        int len = 0, m = b[pos];
        rep(i, n)
        {
            if (a[i] >= m)
            {
                len++;
                v.push_back(a[i]);
                if (a[i] == m)
                    pos++;
            }
            else
            {
                sort(all(v));
                rep(j, len - k + 1) w.push_back(v[j]);
                len = 0;
                v.clear();
            }
        }
        sort(all(v));
        rep(j, len - k + 1) w.push_back(v[j]);
        if (w.size() < q)
            continue;
        sort(all(w));
        ans = min(ans, w[q - 1] - w[0]);
    }
    cout << ans << endl;
}