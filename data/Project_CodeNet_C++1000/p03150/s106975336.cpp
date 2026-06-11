#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (n)-1; i > -1; i--)
#define reps(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define sper(i, s, n) for (int i = (s); i >= (int)(n); i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    bool ok = false;
    rep(i, s.size())
    {
        reps(j, i, s.size())
        {
            string t = s.substr(0, i) + s.substr(j);
            if (t == "keyence")
            {
                ok = true;
            }
            // cout << t << endl;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    solve();
    return 0;
}