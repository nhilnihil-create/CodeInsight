#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    int right = 0, left = 0;
    rep(i, m)
    {
        if (a[i] > x)
            right++;
        else
            left++;
    }
    int ans = min(right, left);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}