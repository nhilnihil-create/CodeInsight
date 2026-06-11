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
    string key = "keyence";
    bool ok = false;
    rep(i, s.size())
    {
        rep(j, s.size())
        {
            string t = s;
            t.erase(i, j);
            if (t == key)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    solve();
    return 0;
}