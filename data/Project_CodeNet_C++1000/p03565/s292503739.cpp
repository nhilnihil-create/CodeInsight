#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    string ans;
    for (int i = 0; i < n; i++) {
        if (i + m - 1 >= n) break;
        bool pass = false;
        string tmp = s;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != '?' && s[i + j] != t[j]) {
                pass = true;
                break;
            } else {
                if (s[i + j] == '?') {
                    tmp[i + j] = t[j];
                }
            }
        }
        if (pass) continue;
        for (int i = 0; i < n; i++) {
            if (tmp[i] == '?') tmp[i] = 'a';
        }
        if (ans.empty()) ans = tmp;
        ans = min(ans, tmp);
    }
    if (ans.empty()) cout << "UNRESTORABLE" << '\n', exit(0);
    cout << ans << '\n';
    return 0;
}