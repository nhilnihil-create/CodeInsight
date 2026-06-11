#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    bool solved = false;
    for (int i = 0; i < min(n, m); i++) {
        if (s[i] != t[i]) {
            solved = true;
            if (s[i] < t[i]) {
                cout << "Yes";
            } else {
                cout << "No";
            }
            break;
        }
    }
    if (!solved) {
        if (n < m) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}