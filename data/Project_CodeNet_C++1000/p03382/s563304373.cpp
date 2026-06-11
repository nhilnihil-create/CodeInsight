#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
int n;

signed main()
{
    cin >> n;
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }
    sort(a.begin(), a.end());
    ll ai = a[n - 1], aj = a[0];
    rep(i, n - 1)
    {
        if (abs(a[i] - ai / 2) <= abs(aj - ai / 2)) {
            aj = a[i];
        }
    }
    cout << ai << " " << aj << endl;
    return 0;
}
