#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i, n) cin >> w[i];
    map<string, int> mp;
    bool ok = true;
    rep(i, n)
    {
        mp[w[i]]++;
        if (i == 0)
            continue;
        int ws = w[i - 1].size() - 1;
        // cout << ws << endl;
        if (w[i - 1][ws] != w[i][0])
            ok = false;
    }
    for (auto p : mp)
    {
        if (p.second > 1)
            ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}