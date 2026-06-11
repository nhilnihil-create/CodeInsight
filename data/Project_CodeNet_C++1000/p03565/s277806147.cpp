#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int index=- 1;
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        bool can = true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i + j] == '?') continue;
            if (s[i + j] != t[j]) can = false;
        }
        if (can) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int j = 0; j < t.size(); j++) {
            s[index + j] = t[j];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') s[i] = 'a';
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    else {
        cout << "UNRESTORABLE" << endl;
    }
    return 0;
}