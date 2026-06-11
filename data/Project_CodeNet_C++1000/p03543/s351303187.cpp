#include <bits/stdc++.h>
using namespace std;

bool is_good(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[0] == s[1]) {
            if (s[0] == s[2]) return true;
            else return false;
        } else {
            if (s[1] == s[2] && s[1] == s[3]) return true;
            else return false;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (is_good(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}