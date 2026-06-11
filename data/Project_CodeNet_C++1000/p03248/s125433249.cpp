#include<bits/stdc++.h>
using namespace std;
main () {
    string s; cin >> s;
    if (s[0] == '0' || s.back() == '1') {
        cout << -1 << endl; exit(0);
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != s[s.size() - i - 2]) {
            cout << -1 << endl; exit(0);
        }
    }
    s = s.substr(0, s.size() - 1);
    int tmp = 1, nxt = 2;
    for (auto&& chr : s) {
        if (chr == '1') {
            cout << tmp << " " << nxt << endl;
            tmp = nxt;
        } else {
            cout << tmp << " " << nxt << endl;
        }
        ++nxt;
    }
}
