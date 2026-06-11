#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        ans = i * i;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}