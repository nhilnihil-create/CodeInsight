#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

vector<int> W;

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
    int ans = b[q - 1] - b[0], pos = 0;
    while (pos + q - 1 < n)
    {
        vector<int> v, w;
        int sum = 0, cnt = 0, num = b[pos];
        rep(i, n)
        {
            if (a[i] >= num)
            {
                cnt++;
                w.push_back(a[i]);
                if (a[i] == num)
                    pos++;
            }
            else
            {
                sort(all(w));
                rep(j, cnt - k + 1)
                    v.push_back(w[j]);
                w = W;
                sum += max(cnt - k + 1, 0LL);
                cnt = 0;
            }
        }
        sum += max(cnt - k + 1, 0LL);
        sort(all(w));
        rep(i, cnt - k + 1)
            v.push_back(w[i]);
        if (sum < q)
            break;
        sort(all(v));
        ans = min(ans, v[q - 1] - v[0]);
    }
    cout << ans << endl;
}