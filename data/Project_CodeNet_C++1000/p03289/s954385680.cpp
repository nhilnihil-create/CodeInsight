#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.at(0) != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    int cnt = 0, idx;
    for (int i = 2, n = s.size() - 2; i <= n; i++)
        if (s.at(i) == 'C') {
            cnt++;
            idx = i;
        }

    if (cnt != 1) {
        cout << "WA" << endl;
        return 0;
    }

    for (int i = 1, n = s.size(); i < n; i++)
        if (i != idx) {
            char c = s.at(i);
            if (!('a' <= c && c <= 'z')) {
                cout << "WA" << endl;
                return 0;
            }
        }

    cout << "AC" << endl;
}