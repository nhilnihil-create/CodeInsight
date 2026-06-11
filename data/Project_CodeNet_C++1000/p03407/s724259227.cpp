#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}