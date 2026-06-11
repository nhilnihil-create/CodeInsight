
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = 1;
    for (int i = 0; i < 3; i++) {
        if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') flag = 1;
    }
    if (flag && s[0] != s[1] && s[1] != s[2] && s[2] != s[0]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
