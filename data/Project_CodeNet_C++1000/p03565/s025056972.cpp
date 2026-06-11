#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t; cin >> s >> t;
    int n = (int) s.size();
    int tz = (int) t.size();
    int i = n - 1;
    bool ok = 0;
    while (i >= tz - 1) {
        ok = 1;
        for (int it = i, j = tz - 1; j >= 0; it--, j--) {
            if (s[it] != '?' && s[it] != t[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int it = i, j = tz - 1; j >= 0; it--, j--) {
                s[it] = t[j];
            }
            break;
        }
        i--;
    }
    if (ok) {
        for (auto c : s) {
            if(c == '?') {
                cout << 'a';
            } else {
                cout << c;
            }
        }
    } else {
        cout << "UNRESTORABLE";
    }

    return 0;
}
