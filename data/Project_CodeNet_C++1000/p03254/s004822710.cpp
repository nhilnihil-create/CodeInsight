#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, n)
    {
        x -= a[i];
        if (x >= 0)
        {
            ans++;
            if (i == n - 1 && x > 0)
                ans--;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}