#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    unordered_map<char, char> m1;
    unordered_map<char, char> m2;
    for (int i = 0; i < t.length(); i++) {
        if (m1.count(t.at(i)) != 0 && m1[t.at(i)] != s.at(i)) {
            cout << "No" << endl;
            return 0;
        }
        m1[t.at(i)] = s.at(i);

        if (m2.count(s.at(i)) != 0 && m2[s.at(i)] != t.at(i)) {
            cout << "No" << endl;
            return 0;
        }
        m2[s.at(i)] = t.at(i);
    }

    cout << "Yes" << endl;
    return 0;
}