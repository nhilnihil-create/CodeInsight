#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'x') t += s[i];
    }
    for (int i = 0; i * 2 < (int)t.size(); i++) {
        if (t[i] != t[t.size() - i - 1]) ans = -1;
    }
    if (ans == 0) {
        int l = 0, r = n - 1;
        while (r - l > 0) {
            if (s[l] != s[r]) {
                ans++;
                if (s[l] == 'x') l++;
                if (s[r] == 'x') r--;
            } else {
                l++;
                r--;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}