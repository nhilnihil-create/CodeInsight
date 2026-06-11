#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());
    int ans = 1e9;
    rep(i, n - k + 1)
    {
        int mn = h[i];
        int mx = h[i + k - 1];
        ans = min(ans, abs(mn - mx));
    }
    cout << ans << endl;
    return 0;
}