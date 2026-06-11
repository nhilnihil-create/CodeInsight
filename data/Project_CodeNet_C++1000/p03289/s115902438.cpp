#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int c_count = 0;
    if(s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    if(isupper(s[1]) || isupper(s[s.size()-1])) {
        cout << "WA" << endl;
        return 0;
    }
    for(int i=2; i<s.size()-1; i++) {
        if(s[i] == 'C') {
            c_count++;
            if(c_count > 1) {
                cout << "WA" << endl;
                return 0;
            }
        }
        else if(isupper(s[i])) {
            cout << "WA" << endl;
            return 0;
        }
    }
    if(c_count == 0) {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
}
