#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b;
    string s;
    cin >> a >> b >> s;

    rep(i, a + b + 1)
    {
        if (i == a)
        {
            if (s[i] != '-')
            {
                cout << "No" << '\n';
                return 0;
            }
        }
        else
        {
            if (!('0' <= s[i] && s[i] <= '9'))
            {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';

    return 0;
}
