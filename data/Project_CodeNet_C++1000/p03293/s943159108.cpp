#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

string rotate(string s)
{
    return s.substr(1) + s[0];
}

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    rep(i, n)
    {
        if (s == t)
        {
            cout << "Yes" << '\n';
            return 0;
        }
        s = rotate(s);
    }
    cout << "No" << '\n';
    return (0);
}

// int main()
// {
//     string s, t;
//     cin >> s >> t;

//     t += t;
//     cout << ((t.find(s) != -1) ? "Yes" : "No") << endl;
//     return (0);
// }
