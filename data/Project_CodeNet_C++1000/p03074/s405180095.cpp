#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> zeros, ones;
    if (s[0] == '0') ones.push_back(0);
    for (auto c: s) {
        if (cnt > 0 && c == '1') {
            zeros.push_back(cnt);
            cnt = 0;
            continue;
        }
        if (c == '0') cnt++;
    }
    if (cnt > 0) zeros.push_back(cnt);
    cnt = 0;
    for (auto c: s) {
        if (cnt > 0 && c == '0') {
            ones.push_back(cnt);
            cnt = 0;
            continue;
        }
        if (c == '1') cnt++;
    }
    ones.push_back(cnt);
    if (k >= zeros.size()) {
        cout << n << endl;
        return 0;
    }
    int acum = ones[0];
    int ans = 0;
    for (int i = 0; i < zeros.size(); i++) {
        acum += zeros[i];
        acum += ones[i+1];
        if (i >= k) {
            acum -= zeros[i-k];
            acum -= ones[i-k];
        }
        // cout << acum << endl;
        ans = max(ans, acum);
    }
    cout << ans << endl;
    // for (auto x: zeros) cout << x << ' ';
    // cout << endl;
    // for (auto x: ones) cout << x << ' ';
    // cout << endl;
    return 0;
}