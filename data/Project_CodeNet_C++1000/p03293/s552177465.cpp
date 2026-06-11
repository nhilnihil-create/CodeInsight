#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s, t;
    cin >> s >> t;
    string u = s;
    rep(i, s.size())
    {
        if (u.substr(0, s.size()) == t)
        {
            cout << "Yes" << endl;
            return 0;
        }
        char tmp = u.back();
        u.erase(u.size() - 1);
        u = tmp + u;
        // cout << u << endl;
    }
    cout << "No" << endl;
    return 0;
}