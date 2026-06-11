#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    string s;
    ll k;
    cin >> s >> k;

    int n = s.size();
    int oneLen = 0;
    rep (i, n)
        if (s[i] == '1')
            oneLen++;
        else
            break;

    cout << (k > oneLen ? s[oneLen] : '1') << endl;
    return 0;
}