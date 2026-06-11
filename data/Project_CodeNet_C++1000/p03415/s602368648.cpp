#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    rep(i, 3) rep(j, 3)
    {
        if (i == j)
            cout << s[i][j];
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}