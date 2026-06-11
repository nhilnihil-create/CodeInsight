/**
*    created: 20.06.2020 13:34:47
**/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int mn = 1000;
    rep(i,s.size()-2) {
        mn = min((int)(abs(stoi(s.substr(i,3))-753)), mn);
    }
    cout << mn << endl;
    return 0;
}