/**
*    created: 14.05.2020 14:18:40
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    if (s == "A") cout << "T" << endl;
    if (s == "C") cout << "G" << endl;
    if (s == "G") cout << "C" << endl;
    if (s == "T") cout << "A" << endl;
    return 0;
}