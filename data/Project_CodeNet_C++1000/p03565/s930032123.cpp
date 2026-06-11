#include <iostream>
#include <set>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    set<string> ans;
    for (int i = 0; i + t.size() <= s.size(); i++) {
        bool flag = true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i+j] != t[j] && s[i+j] != '?') flag = false;
        }
        if (flag) {
            string ss = s;
            for (int j = 0; j < t.size(); j++) ss[i+j] = t[j];
            for (int j = 0; j < s.size(); j++) {
                if (ss[j] == '?') ss[j] = 'a';
            } 
            ans.insert(ss);
        }
    }
    if (ans.size() == 0) cout << "UNRESTORABLE" << endl;
    else cout << *ans.begin() << endl;
}