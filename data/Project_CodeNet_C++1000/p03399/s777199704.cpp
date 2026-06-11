#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min({a + c, a + d, b + c, b + d}) << endl;
}

int main()
{
    solve();
    return 0;
}