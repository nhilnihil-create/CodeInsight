#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool existC = false;
    if (s[0] != 'A' || s[1] < 'a') {
        cout << "WA" << endl;
    } else {
        for (int i=2; i<s.size(); i++) {
            if (s[i] == 'C') {
                if (existC || i==s.size()-1) {
                    cout << "WA" << endl;
                    return 0;
                } else {
                    existC = true;
                }
            } else if (s[i] < 'a') {
                cout << "WA" << endl;
                return 0;
            }
        }
        if (existC) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}