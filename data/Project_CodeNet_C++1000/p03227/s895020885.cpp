#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(a, b, m) for (ll a = (ll)(b); a < (ll)(m); a++)

int main()
{
    string s;
    cin >> s;
    int a = s.size();
    vector<char> v(3);
    if (a == 2)
    {
        cout << s;
    }
    else
    {
        v[0] = s[2];
        v[1] = s[1];
        v[2] = s[0];
        rep(i, 3)
        {
            cout << v[i];
        }
    }
    cout << endl;
}