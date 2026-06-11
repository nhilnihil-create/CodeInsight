#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    vector<int> sChar(26, -1), tChar(26, -1);
    int n = s.size();
    bool ok = true;
    rep (i, n)
    {
        if (sChar[t[i] - 'a'] == -1)
            sChar[t[i] - 'a'] = s[i] - 'a';
        else if (sChar[t[i] - 'a'] != s[i] - 'a')
            ok = false;
        if (tChar[s[i] - 'a'] == -1)
            tChar[s[i] - 'a'] = t[i] - 'a';
        else if (tChar[s[i] - 'a'] != t[i] - 'a')
            ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}