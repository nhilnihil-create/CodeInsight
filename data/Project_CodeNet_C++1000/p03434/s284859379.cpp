#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    int ans = 0;
    rep(i, n)
    {
        if (i % 2 == 0)
            ans += a[i];
        else
            ans -= a[i];
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}