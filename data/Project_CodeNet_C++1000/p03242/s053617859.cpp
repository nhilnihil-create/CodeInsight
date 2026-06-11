/**
*    created: 23.06.2020 23:22:38
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s[0] == '1') s[0] = '9';
    else s[0] = '1';
    if (s[1] == '1') s[1] = '9';
    else s[1] = '1';
    if (s[2] == '1') s[2] = '9';
    else s[2] = '1';
    cout << s << endl;
    return 0;
}