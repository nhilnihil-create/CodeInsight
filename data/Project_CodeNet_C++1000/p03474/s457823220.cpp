#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b;
    string s;
    cin >> a >> b >> s;
    int n = s.size();
    bool ok = true;
    rep(i, n)
    {
        if (i == a)
        {
            if (s[i] != '-')
                ok = false;
        }
        else
        {
            if (s[i] == '-')
                ok = false;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}