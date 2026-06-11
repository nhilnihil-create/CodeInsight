#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;

    bool ok = true;
    rep (i, a + b + 1)
        if (i == a)
        {
            if (s[i] == '-')
                continue;
            ok = false;
        }
        else if ((int)(s[i] - '0') < 0 || (int)(s[i] - '0') > 9)
            ok = false;

    cout << (ok == true ? "Yes" : "No") << endl;
}