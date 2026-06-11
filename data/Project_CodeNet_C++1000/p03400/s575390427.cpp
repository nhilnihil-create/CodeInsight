#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int e = 0;
    rep(i, n)
    {
        int t = 1;
        for (int j = 1; t <= d; j++)
        {
            // cout << t << " ";
            t = a[i] * j + 1;
            e++;
        }
        // cout << endl;
    }
    int ans = e + x;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}