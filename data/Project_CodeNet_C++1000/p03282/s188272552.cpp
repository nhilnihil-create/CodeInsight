#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    ll k;
    cin >> k;

    ll one_length = 0;
    char ans;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] != '1')
        {
            ans = s[i];
            break;
        }
        else
            ++one_length;
    }

    if (k <= one_length)
        cout << "1" << endl;
    else
        cout << ans << endl;
}