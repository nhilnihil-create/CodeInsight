#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;
    int len = s.length();
    map<char, set<int>> mps, mpt;
    for (int i = 0; i < len; ++i)
    {
        mps[s[i]].insert(i);
        mpt[t[i]].insert(i);
    }

    map<char, bool> cs, ct;
    for (int i = 0; i < len; ++i)
        cs[s[i]] = true, ct[t[i]] = true;
    for (auto i : mps)
    {
        for (auto j : mpt)
        {
            if (cs[i.first] && ct[j.first] && i.second == j.second)
                cs[i.first] = false, ct[j.first] = false;
        }
    }
    for (auto i : cs)
    {
        if (i.second)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (auto i : ct)
    {
        if (i.second)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
