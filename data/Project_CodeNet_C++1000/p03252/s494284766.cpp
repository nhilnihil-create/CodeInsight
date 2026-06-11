#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
 
int main(void) {
    string s, t;
    cin >> s >> t;
    char toS[26];
    char toT[26];
    for (Int i = 0; i < 26; ++i) {
        toS[i] = '.';
        toT[i] = '.';
    }
    Int len = t.length();
    bool res = true;
    for (Int i = 0; i < len; ++i) {
        if (toT[(Int)(s[i] - 'a')] == '.') {
            toT[(Int)(s[i] - 'a')] = t[i];
        } else if (toT[s[i] - 'a'] != t[i]) {
            res = false;
        }
        if (toS[(Int)(t[i] - 'a')] == '.') {
            toS[(Int)(t[i] - 'a')] = s[i];
        } else if (toS[t[i] - 'a'] != s[i]) {
            res = false;
        }
    }
    if (res == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
