#include <bits/stdc++.h>
using namespace std;

void solve () {
    string s;
    cin >> s;
    stack<char> t;
    long long ans = 0;
    char x = '0';
    for (int i = 0; i < (int) s.size(); i++) {
        if(t.empty()) {
            if (s[i] == '0') {
                x = '1';
            } else {
                x = '0';
            }
        }
        if (s[i] == x) {
            if (!t.empty()) {
                t.pop();
                ans++;
            }
        } else {
            t.push(s[i]);
        }
    }
    cout << ans * 2ll;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
