#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s[0] == 'A') {
        string t = s.substr(2, s.length()-3);
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == 'C') {
                count ++;
            }
        }
        if (count == 1) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i]!='A' && s[i]!='C') {
                    if ('a'<=s[i] && s[i]<='z') {}
                    else {
                        cout << "WA" << endl;
                        return 0;
                    }
                }
            }
            cout << "AC" << endl;
        }
        else
            cout << "WA" << endl;
    }
    else
        cout << "WA" << endl;
}