#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = "#" + s;
    if (s[1] != '1') {
        cout << -1; return;
    }
    if (s[n] == '1') {
        cout << -1; return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            if (s[n - i] != '1') {
                cout << -1; return;
            }
        }
    }
    vector<int> vt;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') vt.push_back(i);
    }
    vt.push_back(n);
    int k = vt.size();
    for (int i = 1; i < k; i++) {
        if (i > 0) cout << vt[i - 1] << ' ' << vt[i] << "\n";
        for (int j = vt[i - 1] + 1; j < vt[i]; j++) {
            cout << j << ' ' << vt[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}
