#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    rep (i, n)
        cin >> s[i];

    bool ok = true;
    rep (i, n - 1)
        if (s[i][s[i].size() - 1] != s[i + 1][0])
            ok = false;

    sort(s.begin(), s.end());
    rep (i, n - 1)
        if (s[i] == s[i + 1])
            ok = false;

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}