#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int N = S.length();
    int M = T.length();
    for (int i = N - M; i >= 0; i--) {
        string s = S.substr(i, M);
        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (s[j] != '?' && s[j] != T[j]) {
                ok = false;
            }
        }
        if (ok) {
            string ans = S.substr(0, i) + T + S.substr(i + M);
            for (auto& c : ans) {
                if (c == '?') {
                    c = 'a';
                }
            }
            cout << ans << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
}
