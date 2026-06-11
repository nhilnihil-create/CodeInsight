#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    char x, y;
    cin >> x >> y;
    if (x < y)
        cout << "<" << endl;
    else if (x > y)
        cout << ">" << endl;
    else
        cout << "=" << endl;
}

int main()
{
    solve();
    return 0;
}