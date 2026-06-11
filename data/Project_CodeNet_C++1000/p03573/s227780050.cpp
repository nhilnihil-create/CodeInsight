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
    if (a == b)
        cout << c << endl;
    else if (a == c)
        cout << b << endl;
    else if (b == c)
        cout << a << endl;
}

int main()
{
    solve();
    return 0;
}