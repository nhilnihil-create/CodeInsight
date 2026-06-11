#include <bits/stdc++.h>
using namespace std;

signed main () {
    string s, t;
    cin >> s;
    int64_t ans = 0;
    int cur = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        if (i + 1 < int(s.size()) && s.substr(i, 2) == "BC") {
            t += 'D';
            ++i;
        }
        else 
            t += s[i];
        if (t.back() == 'D')
            ans += cur;
        else if (t.back() == 'A')
            ++cur;
        else
            cur = 0;
    }
    cout << ans << '\n';
}
