#include "bits/stdc++.h"
using namespace std;

int main(void) {
    string s;
    cin >> s;
    if (s.length() == 2) {
        cout << s;
    }
    else {
        cout << s[2] << s[1] << s[0];
    }
    return 0;
}