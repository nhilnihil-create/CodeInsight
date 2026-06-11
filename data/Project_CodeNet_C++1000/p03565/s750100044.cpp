#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    string s, t;
    cin >> s >> t;
    if(s.size() < t.size()) {
        cout << "UNRESTORABLE" << '\n';
        return 0;
    }
    bool flag = false;
    int I = -1, ii = 0;
    for(int i = s.size()-1; i >= 0; --i) {
        ii = i+1;
        if(flag) break;
        for(int j = t.size()-1; j >= 0; j--) {
            I = i - (t.size() - j - 1);
            if(I < 0) break;
            if(s[I] == t[j] || s[I] == '?') {
                    if(j == 0) {
                    flag = true;
                }
            } else {
                break;
            }
        }
    }

    if(flag) {
        for(int i = 0; i < s.size(); ++i) {
            if(i >= I && i <= ii) {
                s[i] = t[i - I];
            } else {
                if(s[i] == '?') s[i] = 'a';
            }
        }
        cout << s << '\n';
    } else cout << "UNRESTORABLE" << '\n';

    return 0;
}
