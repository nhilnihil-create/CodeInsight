#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    bool b1 = false, b2 = false, b3 = false;
    if (s[0] == 'A') b1 = true;
    for (int i=2; i<=s.size()-2; ++i) {
        if (s[i] == 'C') b2 = true;
    }
    int cnt = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] < 'a' || 'z' < s[i]) cnt++;
    }
    if (cnt == 2) b3 = true;
    cout <<  (b1 && b2 && b3 ? "AC" : "WA") << endl;
}