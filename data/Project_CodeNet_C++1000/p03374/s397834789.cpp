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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    int N = n + 1;
    vector<int> x(N), y(N), v1(n), v2(n);
    x[0] = y[0] = v1[0] = 0;
    rep(i, n) cin >> x[i + 1] >> v1[i];
    rep(i, n) y[i + 1] = c - x[n - i];
    v2 = v1;
    reverse(all(v2));
    vector<int> a(N), b(N), sum1(N), sum2(N);
    a[0] = b[0] = sum1[0] = sum2[0] = 0;
    rep(i, n)
    {
        sum1[i + 1] = sum1[i] + v1[i];
        sum2[i + 1] = sum2[i] + v2[i];
        a[i + 1] = max(sum1[i + 1] - x[i + 1], a[i]);
        b[i + 1] = max(sum2[i + 1] - y[i + 1], b[i]);
    }
    int ans = 0;
    rep(i, n)
    {
        int tmp = max(sum1[i + 1] - x[i + 1] + max(0LL, b[n - i - 1] - x[i + 1]), sum2[i + 1] - y[i + 1] + max(0LL, a[n - i - 1] - y[i + 1]));
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}