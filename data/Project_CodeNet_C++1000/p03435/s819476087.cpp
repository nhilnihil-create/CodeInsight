#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int c[3][3];

void solve()
{
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    rep(x, 101)
    {
        if (x == 0)
            continue;
        if (x == 2)
            break;
        vector<int> a(3), b(3);
        rep(i, 3) a[i] = c[0][i] - x;
        rep(i, 3) b[i] = c[i][0] - a[0];
        bool ok = true;
        rep(i, 3) rep(j, 3)
        {
            if (a[j] + b[i] != c[i][j])
                ok = false;
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}