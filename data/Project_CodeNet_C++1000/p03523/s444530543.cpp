#include <bits/stdc++.h>
using namespace std;
const string w = "AKIHABARA";
int main() {
    string s;
    cin >> s;

    for (int i = 0; i < w.size(); i++) {
        if (s.size() - 1 < i || (w[i] != s[i] && w[i] == 'A')) {
            string t = "A";
            s.insert(i, t);
        }
    }
    if (s != w) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}