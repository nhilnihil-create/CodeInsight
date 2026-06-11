#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a >= 13)
        ans = b;
    else if (a >= 6)
        ans = b / 2;
    else
        ans = 0;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}