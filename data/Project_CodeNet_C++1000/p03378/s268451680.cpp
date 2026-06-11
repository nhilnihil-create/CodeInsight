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
    vector<int> a(n + 1);
    rep(i, m)
    {
        int p;
        cin >> p;
        a[p] = 1;
    }
    int ans = 1e9, tmp = 0;
    for (int i = x; i >= 0; i--)
    {
        if (a[i] == 1)
            tmp++;
    }
    ans = min(ans, tmp);
    tmp = 0;
    for (int i = x; i <= n; i++)
    {
        if (a[i] == 1)
            tmp++;
    }
    ans = min(ans, tmp);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}