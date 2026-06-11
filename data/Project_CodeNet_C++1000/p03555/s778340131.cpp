#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string s, t;
        cin >> s; cin >> t;
        if (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) {
                cout << "YES" << endl;
        }
        else {
                cout << "NO" << endl;
        }

}
