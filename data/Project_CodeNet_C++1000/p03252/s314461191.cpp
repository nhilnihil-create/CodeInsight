#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    char c[26];
    for (int i = 0; i < 26; i++) {
        c[i] = '+';
    }
    for (int i = 0; i < s.size(); i++) {
        if (c[int(t[i] - 'a')] == '+') {
            c[int(t[i] - 'a')] = s[i];
        }
        else if (c[int(t[i] - 'a')] != s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        c[i] = '+';
    }
    for (int i = 0; i < s.size(); i++) {
        if (c[int(s[i] - 'a')] == '+') {
            c[int(s[i] - 'a')] = t[i];
        }
        else if (c[int(s[i] - 'a')] != t[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}