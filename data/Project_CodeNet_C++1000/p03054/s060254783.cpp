#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int a, b;
    cin >> a >> b;
    string s, t;
    cin >> s >> t;
    int top = 1;
    int bottom = h;
    int left = 1;
    int right = w;
    bool fail = false;
    for (int i = n - 1; i >= 0; --i) {
        if (t[i] == 'U') {
            bottom = min(h, bottom + 1);
        } else if (t[i] == 'D') {
            top = max(1, top - 1);
        } else if (t[i] == 'L') {
            right = min(w, right + 1);
        } else {
            left = max(1, left - 1);
        }
        if (s[i] == 'U') {
            top = max(2, top + 1);
        } else if (s[i] == 'D') {
            bottom = min(h - 1, bottom - 1);
        } else if (s[i] == 'L') {
            left = max(2, left + 1);
        } else {
            right = min(w - 1, right - 1);
        }
        if (top > bottom || left > right) {
            fail = true;
            break;
        }
       // cout << top << " " << bottom << " " << left << " " << right << "\n";
    }
    if (fail || b < left || b > right || a < top || a > bottom) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
