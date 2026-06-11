#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort (s.begin(), s.end());
    sort (t.begin(), t.end());
    reverse (t.begin(), t.end());

    int len = min (s.length(),t.length());
    for (int i = 0; i < len; i++) {
        if (s[i] == t[i])
            continue;
        else if (s[i] < t[i]) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s.length() >= t.length())
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}