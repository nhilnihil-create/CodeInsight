#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string ss = s + s;
    for (int i = 0, n = t.size(); i < n; i++)
        if (ss.substr(i, n) == t) {
            cout << "Yes" << endl;
            return 0;
        }

    cout << "No" << endl;
}