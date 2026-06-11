#include <bits/stdc++.h>
using namespace std;

bool check(string s, string t) {
    
    if (s.size() < t.size()) {
        bool flag = true;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i=0; i<s.size(); i++) {
            if (s[i] != t[i]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    
    for (auto i : s) {
        for (auto j : t) {
            if (i < j) return true;
        }
    }
    
    return false;
}

int main(void){
    string s, t;
    cin >> s >> t;
    cout << (check(s, t) ? "Yes" : "No") << endl;
    return 0;
}