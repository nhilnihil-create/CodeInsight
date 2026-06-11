#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    solve();
    return 0;
}