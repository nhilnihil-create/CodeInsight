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

    int k;
    cin >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[k - i - 1];
    int l = 2, r = 2;
    rep(i, k)
    {
        if ((r / a[i]) * a[i] < l)
        {
            cout << -1 << endl;
            return 0;
        }
        l = ((l + a[i] - 1) / a[i]) * a[i];
        r = (r / a[i]) * a[i] + a[i] - 1;
    }
    cout << l << " " << r << endl;
}