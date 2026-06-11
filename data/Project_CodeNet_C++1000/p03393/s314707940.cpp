#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length() < 26) {
        cout << s;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.find(c) == string::npos) { cout << c; break; }
        }
        return 0;
    }
    string tmp = s;
    bool t = next_permutation(s.begin(), s.end());
    if (!t) { cout << -1; return 0; }
    int cur = 0;
    while (cur < s.size() && s[cur] == tmp[cur]) cout << s[cur++];
    cout << s[cur];
    return 0;
}