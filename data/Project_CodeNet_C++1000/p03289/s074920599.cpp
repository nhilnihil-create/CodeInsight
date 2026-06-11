#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.length();
    int count = 0;
    int c_idx = 0;
    bool con = false;
    if (s[0] == 'A') {
        for (int i = 1; i < len; i++) {
            if (isupper(s[i])) {
                count++;
                if (s[i] == 'C' && 1 < i && i < len-1) {
                    con = true;
                }
            }
        }
    }
        
    if (count == 1 && con) cout << "AC" << endl;
    else cout << "WA" << endl;
}