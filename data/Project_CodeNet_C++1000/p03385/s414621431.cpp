#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool exist[3] = {};
    for (int i=0; i<3; i++) {
        if (s[i] == 'a') {
            exist[0] = true;
        } else if (s[i] == 'b') {
            exist[1] = true;
        } else if (s[i] == 'c') {
            exist[2] = true;
        }
    }
    if (exist[0] && exist[1] && exist[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}