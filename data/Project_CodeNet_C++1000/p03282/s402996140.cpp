#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;
    rep(i, s.size())
    {
        if (s[i] == '1' && i == (k - 1))
        {
            cout << 1 << endl;
            return 0;
        }
        else if (s[i] != '1')
        {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}