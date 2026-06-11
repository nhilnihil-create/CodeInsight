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
    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    vector<string> t(m);
    rep(i, m) cin >> t[i];
    bool ok = true;
    rep(i, m)
    {
        if (mp[t[i]] > 0)
        {
            mp[t[i]]--;
        }
        else
            ok = false;
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