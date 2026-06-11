#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'x') t.push_back(s[i]);
    }
    // string r_t = t;
    // reverse(r_t.begin(), r_t.end());
    // if (t != r_t) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != t[t.size() - 1 - i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    /*
    ababa
    axxxxbxxaxxxxxxxbxaxxxx
    // [0, 4, 2, 7, 1, 4]
    // abs(0 - 4) + abs(4 - 1) + abs(2 - 7)
    -> 4 + 3 + 5 == 12
    */
    vector<int> cnt;
    int crt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'x') {
            cnt.push_back(crt);
            crt = 0;
        } else {
            crt++;
        }
    }
    cnt.push_back(crt);
    // for (int a : cnt) {
    //     cout << a << ' ';
    // }
    int ans = 0;
    for (int i = 0; i < cnt.size(); i++) {
        ans += abs(cnt[i] - cnt[cnt.size() - 1 - i]);
    }
    ans /= 2;
    cout << ans << endl;
}