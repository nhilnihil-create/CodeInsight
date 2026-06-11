
#include <bits/stdc++.h>
using namespace std;

string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    for (int i = n - 1; i >= 0; --i) {
        if ((s[i] == t[0] || s[i] == '?') && n - i >= m) {
            bool ok = true;
            for (int j = 0; j < t.length(); ++j) {
                if (s[i + j] != '?' && s[i + j] != t[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int j = 0; j < m; ++j) {
                    s[i + j] = t[j];
                }
                for (int i = 0; i < n; ++i) {
                    if (s[i] == '?')
                        s[i] = 'a';
                }
                cout << s << endl;
                exit(0);
            }
        }
    }
    cout << "UNRESTORABLE" << endl;

    return 0;
}

