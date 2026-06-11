#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 101234567;

int main() {
    ll ans, cnt;
    string s, t;
    cin >> s;

    for (int i = 0; i < s.size()-1; i++) {
        if (s.substr(i, 2) == "BC") {
            t += 'D';
            i++;
        } else {
            t += s[i];
        }
    }

    ans = cnt = 0;
    for (int i = t.size(); i >= 0; i--) {
        if (t[i] == 'A') {
            ans += cnt;
        } else if (t[i] == 'D') {
            cnt++;
        } else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}
