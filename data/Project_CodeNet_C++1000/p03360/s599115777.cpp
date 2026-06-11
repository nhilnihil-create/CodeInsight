#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    rep(i, k)
    {
        if (a < b)
            swap(a, b);
        if (a < c)
            swap(a, c);
        a *= 2;
    }
    int ans = a + b + c;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}