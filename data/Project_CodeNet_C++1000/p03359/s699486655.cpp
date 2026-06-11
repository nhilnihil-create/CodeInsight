#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a > b)
        ans = a - 1;
    else
        ans = a;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}