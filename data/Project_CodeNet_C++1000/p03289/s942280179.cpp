#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    map<char, int> mp;
    int dai = 0, syou = 0;
    rep(i, s.length())
    {
        if (i == 0)
        {
            if (s[i] != 'A')
            {
                cout << "WA" << endl;
                return 0;
            }
        }
        else if (1 < i && i < s.length() - 1)
        {
            if ('a' <= s[i] - 'a' && s[i] - 'z' <= 'Z')
            {
                cout << "WA" << endl;
                return 0;
            }
            mp[s[i]]++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
            dai++;
        else
            syou++;
    }
    if (mp['C'] != 1 || dai != 2)
    {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
}
